#include "math/vec3.h"

namespace psx {

Vec3& Vec3::operator+=(Vec3 other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vec3& Vec3::operator-=(Vec3 other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vec3& Vec3::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vec3& Vec3::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

float Vec3::length_squared() const
{
    return dot(*this, *this);
}

float Vec3::length() const
{
    return std::sqrt(length_squared());
}

Vec3 Vec3::normalized() const
{
    const float len = length();
    if (len == 0.0f) {
        return Vec3{};
    }

    return *this / len;
}

}

