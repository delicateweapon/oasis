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
    bool is_running;
};
extern struct oasis_meta OasisMeta;

void oasis_init(OasisInitInfo *info);
void oasis_run(void);
void oasis_deinit(void);

void oasis_clear_screen(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

typedef struct {
    SDL_FRect rect;
    void *elements;
} OasisWorld;

typedef struct oasis_actor {
    OasisWorld *super;
    SDL_FRect rect;
    void (*keymap[128])(struct oasis_actor *);
} OasisActor;

OasisWorld *oasis_OasisWorld_create(float x, float y, float w, float h);
OasisActor *oasis_actor_create(OasisWorld *super);
void oasis_actor_assign_key(OasisActor *actor, char key, void (*f)(OasisActor *));
