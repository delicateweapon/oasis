#include "oasis.h"
#include "util.h"

inline void oasis_clear_screen(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(OasisMeta.renderer, r, g, b, a);
    SDL_RenderClear(OasisMeta.renderer);
    SDL_RenderPresent(OasisMeta.renderer);
    LOG_UPDATE("Cleared screen with new background");
}
