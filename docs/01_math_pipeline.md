# Math Pipeline

Every vertex starts in model space. To appear on screen, it passes through several coordinate spaces.

```text
clip = Projection * View * Model * local
```

After projection, the perspective divide converts clip coordinates to normalized device coordinates:

```text
ndc.x = clip.x / clip.w
ndc.y = clip.y / clip.w
ndc.z = clip.z / clip.w
```

Finally, NDC coordinates are mapped to screen pixels.

