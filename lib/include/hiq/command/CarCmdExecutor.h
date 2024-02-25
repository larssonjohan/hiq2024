#pragma once

#include "hiq/command/ICommandExecutor.h"
#include "hiq/vehicle/IVehicle.h"

#include <memory>

namespace hiq {
namespace command {

class CarCmdExecutor : public ICommandExecutor
{
public:
    void performAction(const std::shared_ptr<hiq::vehicle::IVehicle>& vehicle, const char command) final;
};

} // namespace command
} // namespace hiq
