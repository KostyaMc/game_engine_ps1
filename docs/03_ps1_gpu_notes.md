# PS1 GPU Notes

The original PlayStation did not have a modern programmable GPU pipeline.

The CPU and GTE transformed and lit vertices. The GPU then rasterized simple primitives such as flat-shaded, Gouraud-shaded, and textured polygons.

Important limitations for this project:

- No programmable shaders.
- No perspective-correct texture mapping.
- Limited color depth.
- Low internal resolution.
- Limited precision in geometry processing.
- Characteristic vertex wobble and texture swimming.

