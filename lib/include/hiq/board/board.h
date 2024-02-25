#pragma once

#include "hiq/geometry/Point2DFwd.h"

#include <cstdint>

namespace hiq {
namespace board {

class Board
{
public:
    Board(const int32_t width, const int32_t height);

    bool isInside(const geometry::Point2D& point);
private:
    const int32_t m_width;
    const int32_t m_height;
};

} // namespace board
} // namespace hiq
