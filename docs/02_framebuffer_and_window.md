# Framebuffer and Window

SDL2 is used only as a platform layer. It creates a window, receives input events, and presents our software framebuffer.

The renderer itself writes pixels into ordinary CPU memory:

```text
framebuffer[y * width + x] = color
```

For the first milestone the internal resolution is 320x240. The window is larger, but the image comes from the low-resolution framebuffer.

This mirrors an important idea from older console engines: rendering resolution and display size are separate decisions.

