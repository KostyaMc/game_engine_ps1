# Educational PS1-Style 3D Engine

An educational C++ / SDL2 software renderer that recreates the constraints and visual character of late-1990s PlayStation 1 graphics.

The goal is not only to build an engine, but to understand the math, rendering pipeline, and hardware limitations behind early 3D games.

## First Milestone

- Create a 320x240 software framebuffer.
- Present it through SDL2.
- Implement basic vector and matrix math.
- Render the first wireframe cube.

## Build

This project uses CMake and expects SDL2 to be available on the system.

```powershell
cmake -S . -B build
cmake --build build
```

