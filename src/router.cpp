// src/router.cpp
#include "task_manager/router.hpp"
#include "task_manager/handlers/task_handler.hpp"
#include "task_manager/middleware/logger.hpp"

namespace task_manager {

template <typename AppType>
void Router<AppType>::register_all_routes() {
    register_task_routes(app_);
}

// явная инстанциация шаблона
template class Router<crow::App<task_manager::middleware::Logger>>;

} // namespace task_manager
