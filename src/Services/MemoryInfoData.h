#pragma once

#include <cstdio>
#include <map>
#include <time.h>
#include "./MemoryInfo.h"

namespace Services {

    class MemoryInfoData {

    public:
        MemoryInfoData() {


        }

    protected:
        std::map<size_t, std::shared_ptr<MemoryInfo>> data;

    };

}
