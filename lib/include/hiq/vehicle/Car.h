#pragma once

#include "hiq/geometry/Direction.h"
#include "hiq/geometry/Point2D.h"
#include "hiq/vehicle/IVehicle.h"

#include <unordered_map>

#include <cstdint>

namespace hiq {
namespace vehicle {

class Car : public IVehicle
{
public:
    Car(const int32_t x, const int32_t y, const geometry::Direction);
    Car(const geometry::Point2D position, const geometry::Direction);
    
    //! See IVehicle::getDirection.
    geometry::Direction getDirection() const final;

    //! See IVehicle::getPosition.
    geometry::Point2D getPosition() final;
    
    //! See IVehicle::turnLeft.
    void turnLeft() final;

    //! See IVehicle::turnRight.
    void turnRight() final;

    //! See IVehicle::goForward.
    void goForward() final;

    //! See IVehicle::goBackward.
    void goBackward() final;
private:
    int16_t m_currentDirectionIdx{0};
    geometry::Direction m_currentDirection;
    geometry::Point2D m_currentPosition;
    
    std::unordered_map<int16_t, geometry::Direction> m_directions {
        {0, geometry::Direction::NORTH},
        {1, geometry::Direction::EAST},
        {2, geometry::Direction::SOUTH},
        {3, geometry::Direction::WEST}
    };
};

} // namespace vehicle
} // namespace hiq
