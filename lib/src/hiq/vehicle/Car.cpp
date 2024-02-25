#include "hiq/vehicle/Car.h"

#include "hiq/geometry/Direction.h"

using namespace hiq::geometry;

namespace hiq {
namespace vehicle {

Car::Car(const int32_t x, const int32_t y, const Direction direction)
: m_currentDirection{std::move(direction)}
, m_currentPosition{geometry::Point2D(std::move(x), std::move(y))}
{
    m_currentDirectionIdx = direction == Direction::NORTH ? 0
                          : direction == Direction::EAST  ? 1
                          : direction == Direction::SOUTH ? 2
                          : 3;
}

Car::Car(const Point2D position, const Direction direction)
: m_currentDirection{std::move(direction)}
, m_currentPosition{std::move(position)}
{
    m_currentDirectionIdx = direction == Direction::NORTH ? 0
                          : direction == Direction::EAST  ? 1
                          : direction == Direction::SOUTH ? 2
                          : 3;
}

Direction Car::getDirection() const 
{
    return m_currentDirection;
}

Point2D Car::getPosition() 
{
    return m_currentPosition;
}

void Car::turnLeft()
{
    m_currentDirectionIdx = (m_currentDirectionIdx - 1) < 0 ? 3 : m_currentDirectionIdx - 1;
    m_currentDirection = m_directions[m_currentDirectionIdx];
}

void Car::turnRight()
{
    m_currentDirectionIdx = (m_currentDirectionIdx + 1) % 4;
    m_currentDirection = m_directions[m_currentDirectionIdx];
}

void Car::goForward()
{
    if(m_currentDirection == Direction::NORTH)
    {
        m_currentPosition.y += 1;
    }
    else if(m_currentDirection == Direction::SOUTH)
    {
        m_currentPosition.y -= 1;
    }
    else if(m_currentDirection == Direction::EAST)
    {
        m_currentPosition.x += 1;
    }
    else
    {
        m_currentPosition.x -= 1;
    }
}

void Car::goBackward()
{
    if(m_currentDirection == Direction::NORTH)
    {
        m_currentPosition.y -= 1;
    }
    else if(m_currentDirection == Direction::SOUTH)
    {
        m_currentPosition.y += 1;
    }
    else if(m_currentDirection == Direction::EAST)
    {
        m_currentPosition.x -= 1;
    }
    else
    {
        m_currentPosition.x += 1;
    }
}

} // namespace vehicle
} // namespace hiq
