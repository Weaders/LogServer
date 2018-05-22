#pragma once

#include "./MemoryInfo.h"
#include <cstdio>
#include <map>
#include <time.h>

namespace Services {

class MemoryInfoData {

public:
    MemoryInfoData() {
    }

protected:
    std::map<size_t, std::shared_ptr<MemoryInfo>> data;
};

} // namespace Services
