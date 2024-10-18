#include "oasis.h"
#include "util.h"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

bool oasis_inititalized = false;

struct oasis_meta OasisMeta = {
    .window = NULL,
    .renderer = NULL,
    .initialized = false,
    .is_running = false,
};

void oasis_init(OasisInitInfo *info) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    LOG_INIT("SDL");
    OasisMeta.window = SDL_CreateWindow(info->window_title, info->window_width,
                                        info->window_height, SDL_WINDOW_OPENGL);
    LOG_INIT("Window");
    OasisMeta.renderer = SDL_CreateRenderer(OasisMeta.window, NULL);
    LOG_INIT("Renderer");
    OasisMeta.initialized = true;
}
