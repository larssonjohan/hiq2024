#pragma once

#include "hiq/geometry/Direction.h"
#include "hiq/geometry/Point2DFwd.h"

namespace hiq {
namespace vehicle {

class IVehicle
{
public:
    //! Gets the current position of the vehicle.
    virtual geometry::Point2D getPosition() = 0;

    //! Gets the current heading direction of the vehicle.
    virtual geometry::Direction getDirection() const = 0;

    //! Moves the vehicle forwards.
    virtual void goForward() = 0;

    //! Moves the vehicle backwards.
    virtual void goBackward() = 0;

    //! Turns the vehicle left.
    virtual void turnLeft() = 0;

    //! Turns the vehicle right.
    virtual void turnRight() = 0;
};

} // namespace vehicle
} // namespace hiq
