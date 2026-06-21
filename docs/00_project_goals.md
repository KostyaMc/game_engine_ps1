# Project Goals

This engine is a learning project focused on the graphics pipeline used by early 3D games.

The renderer will deliberately avoid modern GPU rendering APIs for triangles. SDL2 is used only for the window, input, timing, and presenting a software framebuffer.

The central idea is to build a clear pipeline:

```text
Model Space -> World Space -> View Space -> Clip Space -> NDC -> Screen Space -> Rasterizer -> Framebuffer
```

