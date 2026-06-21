#pragma once

#include <cmath>

namespace psx {

struct Vec2 {
    float x = 0.0f;
    float y = 0.0f;

    constexpr Vec2() = default;
    constexpr Vec2(float x_value, float y_value)
        : x(x_value),
          y(y_value)
    {
    }

    constexpr Vec2 operator+(Vec2 other) const
    {
        return Vec2{x + other.x, y + other.y};
    }

    constexpr Vec2 operator-(Vec2 other) const
    {
        return Vec2{x - other.x, y - other.y};
    }

    constexpr Vec2 operator-() const
    {
        return Vec2{-x, -y};
    }

    constexpr Vec2 operator*(float scalar) const
    {
        return Vec2{x * scalar, y * scalar};
    }

    constexpr Vec2 operator/(float scalar) const
    {
        return Vec2{x / scalar, y / scalar};
    }

    Vec2& operator+=(Vec2 other);
    Vec2& operator-=(Vec2 other);
    Vec2& operator*=(float scalar);
    Vec2& operator/=(float scalar);

    float length_squared() const;
    float length() const;
    Vec2 normalized() const;
};

constexpr Vec2 operator*(float scalar, Vec2 vector)
{
    return vector * scalar;
}

constexpr float dot(Vec2 a, Vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

}

