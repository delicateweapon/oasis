#include "oasis.h"
#include "util.h"

void oasis_deinit(void) {
    if (!OasisMeta.initialized) {
        LOG_WARN("Cannot deinitialize oasis when it has not been initialized");
        return;
    }
    SDL_DestroyWindow(OasisMeta.window);
    LOG_DEINIT("Window");
    SDL_DestroyRenderer(OasisMeta.renderer);
    LOG_DEINIT("Renderer");
    SDL_Quit();
    LOG_DEINIT("SDL");
}
