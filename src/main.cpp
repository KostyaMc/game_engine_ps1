#include <SDL.h>

#include <cstdint>
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    constexpr int framebufferWidth = 320;
    constexpr int framebufferHeight = 240;
    constexpr int windowScale = 3;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << '\n';
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Educational PS1-Style Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        framebufferWidth * windowScale,
        framebufferHeight * windowScale,
        SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer failed: " << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture* screenTexture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        framebufferWidth,
        framebufferHeight);

    if (!screenTexture) {
        std::cerr << "SDL_CreateTexture failed: " << SDL_GetError() << '\n';
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    std::vector<std::uint32_t> framebuffer(framebufferWidth * framebufferHeight, 0xff101018);

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }

        for (int y = 0; y < framebufferHeight; ++y) {
            for (int x = 0; x < framebufferWidth; ++x) {
                const std::uint8_t r = static_cast<std::uint8_t>((x * 255) / framebufferWidth);
                const std::uint8_t g = static_cast<std::uint8_t>((y * 255) / framebufferHeight);
                const std::uint8_t b = 48;
                framebuffer[y * framebufferWidth + x] =
                    (0xffu << 24) | (static_cast<std::uint32_t>(r) << 16) |
                    (static_cast<std::uint32_t>(g) << 8) | b;
            }
        }

        SDL_UpdateTexture(screenTexture, nullptr, framebuffer.data(), framebufferWidth * sizeof(std::uint32_t));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, screenTexture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(screenTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

