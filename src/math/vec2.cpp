#include "math/vec2.h"

namespace psx {

Vec2& Vec2::operator+=(Vec2 other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vec2& Vec2::operator-=(Vec2 other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2& Vec2::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

Vec2& Vec2::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}

float Vec2::length_squared() const
{
    return dot(*this, *this);
}

float Vec2::length() const
{
    return std::sqrt(length_squared());
}

Vec2 Vec2::normalized() const
{
    const float len = length();
    if (len == 0.0f) {
        return Vec2{};
    }

    return *this / len;
}

}

