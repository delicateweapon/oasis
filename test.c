#include "oasis.h"
#include <stdio.h>

int main(void) {
    OasisInitInfo info = {
        .window_title = "test",
        .window_width = 800,
        .window_height = 500,
    };

    oasis_init(&info);
    oasis_run();
    oasis_deinit();

    return 0;
}
