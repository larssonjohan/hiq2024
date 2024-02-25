#pragma once

#include "Point2DFwd.h"

namespace hiq { 
namespace geometry {

struct Point2D
{
    Point2D(const int32_t x, const int32_t y);
    int32_t x{0};
    int32_t y{0};
};

} // namespace geometry
} // namespace hiq
