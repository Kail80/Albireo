#include <std.h>

struct sprite8 {
    uint x;
    uint y;
    uint8 z;
    uint8 tex[64];
    uint8 alpha[64];
    uint id;
    uint uuid;
};
struct sprite8x16 {
    uint x;
    uint y;
    uint8 z;
    uint8 tex[128];
    uint8 alpha[128];
    uint id;
    uint uuid;
};
struct sprite16 {
    uint x;
    uint y;
    uint8 z;
    uint8 tex[256];
    uint8 alpha[256];
    uint id;
    uint uuid;
};
struct sprite16x32 {
    uint x;
    uint y;
    uint8 z;
    uint8 tex[512];
    uint8 alpha[512];
    uint id;
    uint uuid;
};
struct sprite32 {
    uint x;
    uint y;
    uint8 z;
    uint8 tex[1024];
    uint8 alpha[1024];
    uint id;
    uint uuid;
};
struct sprite32x64 {
    uint x;
    uint y;
    uint8 z;
    uint8 tex[2048];
    uint8 alpha[2048];
    uint id;
    uint uuid;
};
struct sprite64 {
    uint x;
    uint y;
    uint8 z;
    uint8 tex[4096];
    uint8 alpha[4096];
    uint id;
    uint uuid;
};
struct sprite64x128 {
    uint x;
    uint y;
    uint8 z;
    uint8 tex[8192];
    uint8 alpha[8192];
    uint id;
    uint uuid;
};