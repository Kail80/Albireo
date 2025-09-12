#include <std.h>

struct bg_nes { // 256x240
    uint32 tex[61440];
};
struct bg_gbc { // 160x144
    uint32 tex[23040];
};
struct bg_gba { // 240x160
    uint32 tex[38400];
};
struct bg_3ds { // 400x240
    uint32 tex[96000];
};

// x versions are expanded horizontally to have 16:9 aspect ratio 
// (rounded down && incremented by 8)
// xsnes == x3ds ∴ merged to xnes

struct bg_xnes { // 424x240
    uint32 tex[61440];
};
struct bg_xgbc { // 256x144
    uint32 tex[61440];
};
struct bg_xgba { // 280x160
    uint32 tex[38400];
};