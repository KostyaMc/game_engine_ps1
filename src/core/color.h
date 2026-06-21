#pragma once

#include <cstdint>

namespace psx {

struct Color {
    std::uint8_t r = 0;
    std::uint8_t g = 0;
    std::uint8_t b = 0;
    std::uint8_t a = 255;

    static constexpr Color rgb(std::uint8_t red, std::uint8_t green, std::uint8_t blue)
    {
        return Color{red, green, blue, 255};
    }

    std::uint32_t to_argb8888() const;
};

}

