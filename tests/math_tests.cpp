#include "math/vec2.h"
#include "math/vec3.h"

#include <cmath>
#include <cstdlib>
#include <iostream>

namespace {

bool nearly_equal(float a, float b, float epsilon = 0.0001f)
{
    return std::fabs(a - b) <= epsilon;
}

void expect(bool condition, const char* message)
{
    if (!condition) {
        std::cerr << "FAILED: " << message << '\n';
        std::exit(1);
    }
}

}

int main()
{
    const psx::Vec2 a{2.0f, 3.0f};
    const psx::Vec2 b{4.0f, -1.0f};
    const psx::Vec2 sum = a + b;

    expect(nearly_equal(sum.x, 6.0f), "Vec2 addition x");
    expect(nearly_equal(sum.y, 2.0f), "Vec2 addition y");
    expect(nearly_equal(psx::dot(a, b), 5.0f), "Vec2 dot product");

    const psx::Vec3 right{1.0f, 0.0f, 0.0f};
    const psx::Vec3 up{0.0f, 1.0f, 0.0f};
    const psx::Vec3 forward = psx::cross(right, up);

    expect(nearly_equal(forward.x, 0.0f), "Vec3 cross x");
    expect(nearly_equal(forward.y, 0.0f), "Vec3 cross y");
    expect(nearly_equal(forward.z, 1.0f), "Vec3 cross z");

    const psx::Vec3 diagonal{3.0f, 4.0f, 0.0f};
    expect(nearly_equal(diagonal.length(), 5.0f), "Vec3 length");

    const psx::Vec3 normalized = diagonal.normalized();
    expect(nearly_equal(normalized.length(), 1.0f), "Vec3 normalized length");

    std::cout << "All math tests passed.\n";
    return 0;
}

