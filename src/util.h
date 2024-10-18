#pragma once

#include "color.h"
#include <stdio.h>

#define MIN(a, b) (a) < (b) ? (a) : (b)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define CLAMP(v, a, b) (v) < (a) ? (a) : ((v) > (b) ? (b) : (v))

#define LOG_WARN(message)                                                      \
    vfprintf(stderr, "[" ANSI_FG_YELLOW "ERROR" ANSI_RESET "] %s\n",           \
             (void *)message)
#define LOG_ERROR(message)                                                     \
    vfprintf(stderr, "[" ANSI_FG_RED "ERROR" ANSI_RESET "] %s\n",              \
             (void *)message)
#define LOG_INIT(message)                                                      \
    vfprintf(stdout, "[" ANSI_FG_GREEN "INIT" ANSI_RESET "] %s\n",             \
             (void *)message)
#define LOG_DEINIT(message)                                                    \
    vfprintf(stdout, "[" ANSI_FG_GREEN "DEINIT" ANSI_RESET "] %s\n",           \
             (void *)message)
