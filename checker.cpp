#include "checker.h"

Status classify(float value, const Range& range) {
    if (value < range.min) return Status::TOO_LOW;
    if (value > range.max) return Status::TOO_HIGH;
    return Status::OK;
}

std::string statusToString(Status s) {
    switch(s) {
        case Status::OK: return "OK";
        case Status::TOO_LOW: return "Too Low";
        case Status::TOO_HIGH: return "Too High";
    }
    return "Unknown";
}
