#include "run.h"

#include "oasis.h"
#include "util.h"

void oasis_run(void) {
    if (!OasisMeta.initialized) {
        LOG_ERROR("Cannot run the program when no initialization has beeen done");
    }

    OasisMeta.is_running = true;
    LOG_SWITCH("Running false -> true");
    SDL_Event event;

    oasis_clear_screen(220, 90, 190, 255);

    while (OasisMeta.is_running) {
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
            case SDL_EVENT_QUIT:
                OasisMeta.is_running = false;
                LOG_SWITCH("Running true -> false");
                SDL_Event event;
                break;
            case SDL_EVENT_KEY_DOWN:
                handle_key_down(event.key);
            }
        }
    }
}

void handle_key_down(SDL_KeyboardEvent key) {
    switch (key.scancode) {
    case SDL_SCANCODE_Q:
        OasisMeta.is_running = false;
        break;
    default:
        break;
    }
}
