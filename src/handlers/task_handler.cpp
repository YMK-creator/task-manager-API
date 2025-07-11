#include "task_manager/handlers/task_handler.hpp"
#include "task_manager/middleware/logger.hpp"
#include <crow/json.h>
#include <mutex>
#include <vector>
#include <string>

namespace task_manager {

// Простая структура задачи
struct Task {
    int id;
    std::string title;
};

// Хранилище задач (в памяти)
std::vector<Task> tasks;
std::mutex tasks_mutex;
int next_id = 1;

template <typename App>
void register_task_routes(App& app) {
    CROW_ROUTE(app, "/task")
    .methods(crow::HTTPMethod::GET)([] {
        std::lock_guard<std::mutex> lock(tasks_mutex);

        std::vector<crow::json::wvalue> tasks_json;
        for (const auto& task : tasks) {
            crow::json::wvalue task_json;
            task_json["id"] = task.id;
            task_json["title"] = task.title;
            tasks_json.push_back(std::move(task_json));
        }

        crow::json::wvalue response;
        response["tasks"] = std::move(tasks_json);

        return crow::response{response};
    });

    CROW_ROUTE(app, "/task/add")
    .methods(crow::HTTPMethod::POST)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("title")) {
            return crow::response(400, "Missing 'title' field");
        }

        std::string title = body["title"].s();

        std::lock_guard<std::mutex> lock(tasks_mutex);
        Task task{next_id++, title};
        tasks.push_back(task);

        crow::json::wvalue result;
        result["status"] = "success";
        result["task"]["id"] = task.id;
        result["task"]["title"] = task.title;

        return crow::response{result};
    });
}

// Явная инстанциация шаблона
template void register_task_routes<crow::App<task_manager::middleware::Logger>>(
    crow::App<task_manager::middleware::Logger>&
);

} // namespace task_manager
