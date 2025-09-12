#include <std.h>

// 46080 == 16min of audio pitched at 48hertz
// 15360 == 16min of audio volumed at 16hertz
// 960 == 16min of audio panned at 1hertz
struct audio {
    uint time;
    uint8 priority;
    uint pulse1pitch[46080];
    uint pulse2pitch[46080];
    uint square1pitch[46080];
    uint square2pitch[46080];
    uint trianglepitch[46080];
    uint noisepitch[46080];
    uint sawtoothpitch[46080];
    uint sinepitch[46080];
    uint pulse1vol[15360];
    uint pulse2vol[15360];
    uint square1vol[15360];
    uint square2vol[15360];
    uint trianglevol[15360];
    uint noisevol[15360];
    uint sawtoothvol[15360];
    uint sinevol[15360];
    uint8 pulse1pan[960];
    uint8 pulse2pan[960];
    uint8 square1pan[960];
    uint8 square2pan[960];
    uint8 trianglepan[960];
    uint8 noisepan[960];
    uint8 sawtoothpan[960];
    uint8 sinepan[960];
};