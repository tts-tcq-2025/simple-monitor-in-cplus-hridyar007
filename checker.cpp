#include "checker.h"
#include <array>

// classify without branching (complexity = 1)
Status classify(float value, const Range& range) {
    return (value < range.min) ? Status::TOO_LOW :
           (value > range.max) ? Status::TOO_HIGH :
                                 Status::OK;
}

// mapping table (complexity = 1)
std::string statusToString(Status s) {
    static const std::array<std::string, 3> table = {
        "OK", "Too Low", "Too High"
    };
    return table[static_cast<int>(s)];
}
