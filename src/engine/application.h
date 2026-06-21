#pragma once

#include "core/framebuffer.h"

#include <SDL.h>

namespace psx {

struct ApplicationConfig {
    int framebuffer_width = 320;
    int framebuffer_height = 240;
    int window_scale = 3;
};

class Application {
public:
    explicit Application(ApplicationConfig config);
    ~Application();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    bool initialize();
    int run();

private:
    void handle_events();
    void update();
    void render_demo_pattern();
    void present();
    void shutdown();

    ApplicationConfig config_;
    Framebuffer framebuffer_;
    bool running_ = false;

    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
    SDL_Texture* screen_texture_ = nullptr;
};

}

