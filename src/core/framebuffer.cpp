#include "core/framebuffer.h"

#include <algorithm>

namespace psx {

Framebuffer::Framebuffer(int width, int height)
    : width_(width),
      height_(height),
      pixels_(static_cast<std::size_t>(width * height), 0)
{
}

int Framebuffer::width() const
{
    return width_;
}

int Framebuffer::height() const
{
    return height_;
}

const std::uint32_t* Framebuffer::pixels() const
{
    return pixels_.data();
}

std::uint32_t* Framebuffer::pixels()
{
    return pixels_.data();
}

void Framebuffer::clear(Color color)
{
    std::fill(pixels_.begin(), pixels_.end(), color.to_argb8888());
}

void Framebuffer::set_pixel(int x, int y, Color color)
{
    if (x < 0 || y < 0 || x >= width_ || y >= height_) {
        return;
    }

    pixels_[static_cast<std::size_t>(y * width_ + x)] = color.to_argb8888();
}

}

