#include "task_manager/server.hpp"
#include "task_manager/handlers/task_handler.hpp"
#include "task_manager/middleware/logger.hpp"

namespace task_manager {

void setup_routes(crow::App<task_manager::middleware::Logger>& app) {
    register_task_routes(app);
}

}  // namespace task_manager
