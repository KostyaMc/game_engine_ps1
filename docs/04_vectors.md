# Vectors

A vector stores a direction and magnitude. In an engine, vectors are used for positions, directions, normals, velocity, texture coordinates, and many intermediate rendering values.

## Vec2

`Vec2` is useful for screen coordinates and texture coordinates:

```text
v = (x, y)
```

Vector addition:

```text
a + b = (a.x + b.x, a.y + b.y)
```

Scalar multiplication:

```text
v * s = (v.x * s, v.y * s)
```

Dot product:

```text
dot(a, b) = a.x * b.x + a.y * b.y
```

The dot product tells us how much two vectors point in the same direction.

## Vec3

`Vec3` is used for 3D positions, directions, normals, and lighting.

Dot product:

```text
dot(a, b) = a.x * b.x + a.y * b.y + a.z * b.z
```

Cross product:

```text
cross(a, b) =
(
    a.y * b.z - a.z * b.y,
    a.z * b.x - a.x * b.z,
    a.x * b.y - a.y * b.x
)
```

The cross product returns a vector perpendicular to both input vectors. We will use it for triangle normals and backface culling.

## PS1 Note

The original PlayStation did not process geometry with modern floating-point shader cores. Transform and lighting work was assisted by the GTE, which used fixed-point style integer math. We start with `float` because it makes the formulas clear, then later we will intentionally quantize values to emulate the old precision limits.

