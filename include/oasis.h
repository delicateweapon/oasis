#pragma once

#include <SDL3/SDL.h>
#include <stdbool.h>

typedef struct {
    char *window_title;
    int window_width;
    int window_height;
} OasisInitInfo;

struct oasis_meta {
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool initialized;
};
extern struct oasis_meta OasisMeta;

void oasis_init(OasisInitInfo *info);

void oasis_deinit(void);
