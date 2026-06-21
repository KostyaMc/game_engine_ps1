#include "engine/application.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    psx::Application app({
        .framebuffer_width = 320,
        .framebuffer_height = 240,
        .window_scale = 3,
    });

    return app.run();
}
