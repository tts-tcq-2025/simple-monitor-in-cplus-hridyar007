#ifndef CHECKER_H
#define CHECKER_H

#include <string>

enum class Status { OK, TOO_LOW, TOO_HIGH };

struct Range {
    float min;
    float max;
    std::string name;
};

Status classify(float value, const Range& range);
std::string statusToString(Status s);

#endif
