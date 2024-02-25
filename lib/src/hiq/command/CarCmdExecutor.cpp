#include "hiq/command/CarCmdExecutor.h"

#include <memory>
#include <iostream>

using namespace hiq::geometry;

namespace hiq {
namespace command {

void CarCmdExecutor::performAction(const std::shared_ptr<hiq::vehicle::IVehicle>& car, const char command)
{
    switch(command)
    {
        case 'F':
        {
            car->goForward();
            break;
        }
        case 'B':
        {
            car->goBackward();
            break;
        }
        case 'L':
        {
            car->turnLeft();
            break;
        }
        case 'R':
        {
            car->turnRight();
            break;
        }
        default:
        {
            std::string error{"Unsupported command: " + std::to_string(command)};
            throw(std::runtime_error(error.c_str()));
        }
    }
}


} // namespace command
} // namespace hiq
