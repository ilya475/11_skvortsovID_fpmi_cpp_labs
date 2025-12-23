#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <string>
#include "time_utility.h"

using TrainId = size_t;
using namespace time_utility;


enum class TrainType {
    PASSENGER, FREIGHT, HIGH_SPEED, SUBWAY, SPECIALIZED
};


class Train {
private:
    TrainId id_;
    TrainType type_;
    std::string destination_;
    std::time_t dispatch_time_;
    std::time_t travelling_time_;

public:
    Train() = default;

    Train(TrainId id, TrainType type, const std::string& destination,
        std::time_t dispatch_time, std::time_t travelling_time)
        : id_(id), type_(type), destination_(destination),
        dispatch_time_(dispatch_time), travelling_time_(travelling_time) {
    }

    TrainId GetId() const {
        return id_;
    }

    TrainType GetType() const {
        return type_;
    }

    const std::string& GetDestination() const {
        return destination_;
    }

    std::time_t GetDispatchTime() const {
        return dispatch_time_;
    }

    std::time_t GetTravellingTime() const {
        return travelling_time_;
    }

    bool operator<(const Train& other) const {
        return dispatch_time_ < other.dispatch_time_;
    }
};
