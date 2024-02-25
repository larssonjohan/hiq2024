#pragma once

#include "hiq/vehicle/IVehicle.h"

#include <memory>

namespace hiq {
namespace command {

class ICommandExecutor 
{
public:
    //! Performs the action as stated in command on the given vehicle.
    virtual void performAction(const std::shared_ptr<hiq::vehicle::IVehicle>& vehicle, const char command) = 0;
};

} // namespace command
} // namespace hiq
