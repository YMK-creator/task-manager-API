#pragma once

#include <crow.h>
#include <string>

namespace task_manager {

template <typename App>
void register_task_routes(App& app);

}
