# Educational PS1-Style 3D Engine

An educational C++20 and SDL2 software renderer inspired by the constraints,
math, and visual character of late-1990s PlayStation 1 graphics.

The goal is not just to build a small engine, but to make every step of the
classic 3D rendering pipeline understandable: vectors, transforms, projection,
rasterization, framebuffer output, and the deliberate limitations that shaped
early 3D games.

## Features

- 320x240 software framebuffer presented through SDL2.
- Simple application loop with window creation, event handling, update, and
  present stages.
- Core color and framebuffer types.
- Basic `Vec2` and `Vec3` math utilities with tests.
- Documentation notes for the rendering pipeline, PS1 GPU behavior, vectors,
  and project goals.

## Project Layout

```text
assets/      Placeholder folders for models, scenes, and textures.
docs/        Learning notes and engine design documentation.
examples/    Future sample scenes and demos.
src/         Engine source code.
tests/       Small executable tests for engine modules.
tools/       Future helper scripts and asset tools.
```

## Requirements

- CMake 3.20 or newer.
- A C++20 compiler.
- SDL2.
- vcpkg is recommended for dependency management.

## Build

Using the vcpkg manifest:

```powershell
cmake -S . -B build-vcpkg -DCMAKE_TOOLCHAIN_FILE="$env:VCPKG_ROOT\scripts\buildsystems\vcpkg.cmake"
cmake --build build-vcpkg
```

If SDL2 is already available to CMake on your system:

```powershell
cmake -S . -B build
cmake --build build
```

## Run

```powershell
.\build-vcpkg\Debug\psx_engine.exe
```

The current executable opens an SDL2 window scaled from the internal 320x240
framebuffer and renders a demo pattern.

## Tests

```powershell
.\build-vcpkg\Debug\psx_math_tests.exe
```

Expected output:

```text
All math tests passed.
```

## Roadmap

The first milestone is focused on the minimum useful software-rendering loop:

- Create and present a low-resolution framebuffer.
- Build vector and matrix math foundations.
- Render the first wireframe cube.
- Expand toward a PS1-style transform, clipping, and rasterization pipeline.

See [ROADMAP.md](ROADMAP.md) and the files in [docs](docs/) for more detail.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for the
full text.
