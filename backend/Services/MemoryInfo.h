#pragma once

#include "../ThirdParty/json.hpp"
#include <cstdio>
#include <sys/sysinfo.h>

namespace Services {

class MemoryInfo {

public:
    MemoryInfo();

    size_t allMemory;
    size_t freeMemory;
    size_t usageMemory;
};

void to_json(nlohmann::json& j, const MemoryInfo&);
void from_json(const nlohmann::json& j, MemoryInfo&);
} // namespace Services