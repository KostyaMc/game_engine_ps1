#pragma once

#include "core/color.h"

#include <cstdint>
#include <vector>

namespace psx {

class Framebuffer {
public:
    Framebuffer(int width, int height);

    int width() const;
    int height() const;
    const std::uint32_t* pixels() const;
    std::uint32_t* pixels();

    void clear(Color color);
    void set_pixel(int x, int y, Color color);

private:
    int width_ = 0;
    int height_ = 0;
    std::vector<std::uint32_t> pixels_;
};

}

