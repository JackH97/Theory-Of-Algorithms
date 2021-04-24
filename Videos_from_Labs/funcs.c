#include <stdio.h>
#include <inttypes.h>

#define W 32
#define WORD uint32_t
#define PF PRIX32

// Page 5 of the secure hash standard
#define ROTL(x,n) (x<<n)|(x>>(W-n))
#define ROTR(x,n) (x>>n)|(x<<(W-n))
#define SHR(x,n) x>>n

// Page 10 of the secure hash standard
#define CH(x,y,z) (x&y)^(~x&z)
#define MAJ(x,y,z) (x&y)^(x&z)^(y&z)

#define SIG0(x) ROTR(x,2)^ROTR(x,13)^ROTR(x,22)
#define SIG1(x) ROTR(x,6)^ROTR(x,11)^ROTR(x,25)
#define Sig0(x) ROTR(x,7)^ROTR(x,18)^SHR(x,3)
#define Sig1(x) ROTR(x,17)^ROTR(x,19)^SHR(x,10)

const WORD K[] = { 
0X428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 
0X3956c25b, 0X59f111f1, 0X923f82a4, 0Xab1c5ed5,
0Xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 
0X72be5d74, 0X80deb1fe, 0X9bdc06a7, 0Xc19bf174,
0Xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 
0X2de92c6f, 0X4a7484aa, 0X5cb0a9dc, 0X76f988da,
0X983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 
0Xc6e00bf3, 0Xd5a79147, 0X06ca6351, 0X14292967,
0X27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 
0X650a7354, 0X766a0abb, 0X81c2c92e, 0X92722c85,
0Xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 
0Xd192e819, 0Xd6990624, 0Xf40e3585, 0X106aa070,
0X19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 
0X391c0cb3, 0X4ed8aa4a, 0X5b9cca4f, 0X682e6ff3,
0X748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 
0X90befffa, 0Xa4506ceb, 0Xbef9a3f7, 0Xc67178f2
};


int main(int argc, char *argv[])
{
    WORD x = 0xF1234567;
    WORD y = 0x0A0A0A0A;
    WORD z = 0xB0B0B0B0;

    WORD ans;

    ans = CH(x,y,z);
    printf("Ch(%08" PF ",%08" PF ",%08" PF ")=%08" PF "\n", x, y, z, ans);

    ans = MAJ(x,y,z);
    printf("Maj(%08" PF ",%08" PF ",%08" PF ")=%08" PF "\n", x, y, z, ans);


    printf("ROTL(%08" PF " -> %08" PF "\n", x, ROTL(x,4));
    printf("ROTR(%08" PF " -> %08" PF "\n", x, ROTR(x,4));

    printf("SHR(%08" PF " -> %08" PF "\n", x, SHR(x,4));

    printf("SIG0(%08" PF " -> %08" PF "\n", x, SIG0(x));
    printf("SIG1(%08" PF " -> %08" PF "\n", x, SIG1(x));
    printf("Sig0(%08" PF " -> %08" PF "\n", x, Sig0(x));
    printf("Sig1(%08" PF " -> %08" PF "\n", x, Sig1(x));

    printf("K[0] = %08" PF "\tK[63] = %08" PF "\n", K[0], K[63]);

    return 0;
}