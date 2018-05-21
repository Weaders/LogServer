#include "MemoryInfo.h"

namespace Services {

MemoryInfo::MemoryInfo() {

    struct sysinfo info;
    sysinfo(&info);

    this->allMemory = info.totalram;
    this->freeMemory = info.freeram;
    this->usageMemory = this->allMemory - this->freeMemory;
}

void to_json(nlohmann::json& j, const MemoryInfo& m) {

    j = nlohmann::json{ { "allMemory", m.allMemory },
        { "freeMemory", m.freeMemory },
        { "usageMemory", m.usageMemory } };
}

void from_json(const nlohmann::json& j, MemoryInfo& m) {

    m.usageMemory = j.at("usageMemory").get<size_t>();
    m.freeMemory = j.at("freeMemory").get<size_t>();
    m.usageMemory = j.at("usageMemory").get<size_t>();
}

} // namespace Services