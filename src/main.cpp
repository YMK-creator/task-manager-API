#include <crow.h>
#include "task_manager/router.hpp"
#include "task_manager/middleware/logger.hpp"

int main() {
    using AppType = crow::App<task_manager::middleware::Logger>;
    AppType app;

    task_manager::Router router(app);
    router.register_all_routes();

    app.port(18080).multithreaded().run();
    return 0;
}
