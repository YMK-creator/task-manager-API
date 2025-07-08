#pragma once
#include <crow.h>

namespace task_manager {

template <typename AppType>
class Router {
public:
    explicit Router(AppType& app) : app_(app) {}

    void register_all_routes();

private:
    AppType& app_;
};

} // namespace task_manager
