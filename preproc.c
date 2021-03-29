#include <stdio.h>
#include <inttypes.h>

#define W 32
#define WORD uint32_t
#define PF PRIX32
#define BYTE uint8_t

union Block {
    BYTE bytes[64];
    WORD words[16];
};

enum Status {
    READ, PAD0, PAD1, END
};

// Get the next block.
int next_block(FILE *f, union Block *B, enum Status *S, uint64_t *nobits)
{
    // Same here.
        nobytes = fread(&B.bytes, 1, 64, f);
        printf("Read %d bytes.\n", nobytes);
        nobits = nobits + (8 * nobytes);
        // Print the 16 32-bit words.
        for (i = 0; i < 16; i++) {
            printf("%08" PF " ", B.words[i]);
            if ((i + 1) % 8 == 0)
                printf("\n");
        }
}

int main(int argc, char *argv[]) {

    // Iterator.
    int i;

    // The current block.
    union Block B;

    // Total number of bits read.
    uint64_t nobits = 0;

    // File pointer for reading.
    FILE *f;

    // Open file from command line for reading.
    f = fopen(argv[1], "r");
    
    // Number of bytes read.
    size_t nobytes;

    // Loop through (preprocessed) the blocks.
    while (next_block(f, &B, &S, &nobits)) {
        for (i = 0; i < 16; i++) {
            printf("%08" PF " ", B.words[i]);
        }
        printf("\n");
    }
    // Close the file.
    fclose(f);
    // Print total number of bits read.
    printf("Total bits read: %d.\n", nobits);

    return 0;
}