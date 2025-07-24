#include "task_manager/handlers/task_handler.hpp"
#include "task_manager/middleware/logger.hpp"
#include "task_manager/utils/db_config.hpp"

#include <crow/json.h>
#include <pqxx/pqxx>
#include <string>

namespace task_manager {

template <typename App>
void register_task_routes(App& app) {
    CROW_ROUTE(app, "/tasks")
    .methods(crow::HTTPMethod::GET)([] {
        try {
            pqxx::connection conn(task_manager::utils::get_connection_string());
            pqxx::read_transaction tx(conn);

            pqxx::result result = tx.exec("SELECT id, title FROM tasks ORDER BY id");

            crow::json::wvalue response;
            std::vector<crow::json::wvalue> tasks_json;

            for (const auto& row : result) {
                crow::json::wvalue task_json;
                task_json["id"] = row["id"].as<int>();
                task_json["title"] = row["title"].as<std::string>();
                tasks_json.push_back(std::move(task_json));
            }

            response["tasks"] = std::move(tasks_json);
            return crow::response{response};
        } catch (const std::exception& e) {
            return crow::response(500, std::string("Database error: ") + e.what());
        }
    });

    CROW_ROUTE(app, "/task/add")
    .methods(crow::HTTPMethod::POST)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("title")) {
            return crow::response(400, "Missing 'title' field");
        }

        std::string title = body["title"].s();

        try {
            pqxx::connection conn(task_manager::utils::get_connection_string());
            pqxx::work tx(conn);

            pqxx::result result = tx.exec_params(
                "INSERT INTO tasks (title) VALUES ($1) RETURNING id",
                title
            );

            tx.commit();

            int task_id = result[0]["id"].as<int>();

            crow::json::wvalue response;
            response["status"] = "success";
            response["task"]["id"] = task_id;
            response["task"]["title"] = title;

            return crow::response{response};
        } catch (const std::exception& e) {
            return crow::response(500, std::string("Database error: ") + e.what());
        }
    });
}

// Явная инстанциация
template void register_task_routes<crow::App<task_manager::middleware::Logger>>(
    crow::App<task_manager::middleware::Logger>&
);

} // namespace task_manager
