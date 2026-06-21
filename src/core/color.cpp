#include "core/color.h"

namespace psx {

std::uint32_t Color::to_argb8888() const
{
    return (static_cast<std::uint32_t>(a) << 24) |
           (static_cast<std::uint32_t>(r) << 16) |
           (static_cast<std::uint32_t>(g) << 8) |
           static_cast<std::uint32_t>(b);
}

}

