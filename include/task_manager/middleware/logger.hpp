#pragma once
#include <crow.h>
#include <iostream>

namespace task_manager::middleware {

struct Logger {
    struct context {};

    void before_handle(crow::request& req, crow::response& res, context&) {
        std::cout << "[Request] " << crow::method_name(req.method) << " " << req.url << std::endl;
    }

    void after_handle(crow::request& /*req*/, crow::response& /*res*/, context&) {
        // Можно оставить пустым
    }
};

} // namespace task_manager::middleware
