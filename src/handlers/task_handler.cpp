#include "task_manager/handlers/task_handler.hpp"
#include "task_manager/middleware/logger.hpp"  

namespace task_manager {

template <typename App>
void register_task_routes(App& app) {
    CROW_ROUTE(app, "/task")
    ([] {
        return "GET: List of tasks";
    });

    CROW_ROUTE(app, "/task/add")
    .methods(crow::HTTPMethod::POST)([] {
        return "POST: Add task";
    });
}

template void register_task_routes<crow::App<task_manager::middleware::Logger>>(
    crow::App<task_manager::middleware::Logger>&
);

} // namespace task_manager
