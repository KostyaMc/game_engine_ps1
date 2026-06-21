#pragma once

#include <cmath>

namespace psx {

struct Vec3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    constexpr Vec3() = default;
    constexpr Vec3(float x_value, float y_value, float z_value)
        : x(x_value),
          y(y_value),
          z(z_value)
    {
    }

    constexpr Vec3 operator+(Vec3 other) const
    {
        return Vec3{x + other.x, y + other.y, z + other.z};
    }

    constexpr Vec3 operator-(Vec3 other) const
    {
        return Vec3{x - other.x, y - other.y, z - other.z};
    }

    constexpr Vec3 operator-() const
    {
        return Vec3{-x, -y, -z};
    }

    constexpr Vec3 operator*(float scalar) const
    {
        return Vec3{x * scalar, y * scalar, z * scalar};
    }

    constexpr Vec3 operator/(float scalar) const
    {
        return Vec3{x / scalar, y / scalar, z / scalar};
    }

    Vec3& operator+=(Vec3 other);
    Vec3& operator-=(Vec3 other);
    Vec3& operator*=(float scalar);
    Vec3& operator/=(float scalar);

    float length_squared() const;
    float length() const;
    Vec3 normalized() const;
};

constexpr Vec3 operator*(float scalar, Vec3 vector)
{
    return vector * scalar;
}

constexpr float dot(Vec3 a, Vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

constexpr Vec3 cross(Vec3 a, Vec3 b)
{
    return Vec3{
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x,
    };
}

}

