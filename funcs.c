#include <stdio.h>
#include <inttypes.h>

#define WORD uint32_t

uint32_t ch(uint32_t x, uint32_t y, uint32_t z)
{
    return (x&y)^(~x&z);
}

int main(int argc, char *argv[])
{
    uint32_t x = 0xf0f0f0f0;
    uint32_t y = 0x0f0f0f0f;
    uint32_t z = 0xf0f0f0f0;

    uint32_t ans = Ch(x, y, z);

    print("Ch(%d,%d,%d)=%d\n", x, y, z, ans);

    return 0;
}