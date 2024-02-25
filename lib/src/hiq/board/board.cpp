#include "hiq/board/board.h"

#include "hiq/geometry/Point2D.h"

#include <utility>

using hiq::geometry::Point2D;

namespace hiq {
namespace board {

Board::Board(const int32_t width, const int32_t height)
: m_width{std::move(width)}
, m_height{std::move(height)}
{
}

bool Board::isInside(const Point2D& point)
{
    return point.x >= 0 && point.x <= m_width 
        && point.y >= 0 && point.y <= m_height;

}

} // namespace map
} // namespace hiq
