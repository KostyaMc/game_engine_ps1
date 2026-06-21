#include "engine/application.h"

#include <iostream>

namespace psx {

Application::Application(ApplicationConfig config)
    : config_(config),
      framebuffer_(config.framebuffer_width, config.framebuffer_height)
{
}

Application::~Application()
{
    shutdown();
}

bool Application::initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << '\n';
        return false;
    }

    window_ = SDL_CreateWindow(
        "Educational PS1-Style Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        config_.framebuffer_width * config_.window_scale,
        config_.framebuffer_height * config_.window_scale,
        SDL_WINDOW_SHOWN);

    if (!window_) {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << '\n';
        return false;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer_) {
        std::cerr << "SDL_CreateRenderer failed: " << SDL_GetError() << '\n';
        return false;
    }

    screen_texture_ = SDL_CreateTexture(
        renderer_,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        config_.framebuffer_width,
        config_.framebuffer_height);

    if (!screen_texture_) {
        std::cerr << "SDL_CreateTexture failed: " << SDL_GetError() << '\n';
        return false;
    }

    running_ = true;
    return true;
}

int Application::run()
{
    if (!initialize()) {
        return 1;
    }

    while (running_) {
        handle_events();
        update();
        render_demo_pattern();
        present();
    }

    return 0;
}

void Application::handle_events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running_ = false;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            running_ = false;
        }
    }
}

void Application::update()
{
}

void Application::render_demo_pattern()
{
    framebuffer_.clear(Color::rgb(16, 16, 24));

    for (int y = 0; y < framebuffer_.height(); ++y) {
        for (int x = 0; x < framebuffer_.width(); ++x) {
            const auto r = static_cast<std::uint8_t>((x * 255) / framebuffer_.width());
            const auto g = static_cast<std::uint8_t>((y * 255) / framebuffer_.height());
            framebuffer_.set_pixel(x, y, Color::rgb(r, g, 48));
        }
    }
}

void Application::present()
{
    SDL_UpdateTexture(
        screen_texture_,
        nullptr,
        framebuffer_.pixels(),
        framebuffer_.width() * static_cast<int>(sizeof(std::uint32_t)));

    SDL_RenderClear(renderer_);
    SDL_RenderCopy(renderer_, screen_texture_, nullptr, nullptr);
    SDL_RenderPresent(renderer_);
}

void Application::shutdown()
{
    if (screen_texture_) {
        SDL_DestroyTexture(screen_texture_);
        screen_texture_ = nullptr;
    }

    if (renderer_) {
        SDL_DestroyRenderer(renderer_);
        renderer_ = nullptr;
    }

    if (window_) {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }

    SDL_Quit();
}

}

