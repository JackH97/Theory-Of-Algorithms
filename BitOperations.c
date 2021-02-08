#include <stdio.h>

void bin_print(int i) {
    int j = sizeof(int) * 8;

    // Temporary Variable.
    int k;

    // Loop over the number of bits in i.
    for (j-- ; j >=0; j--) {
        //
        k = ((1 << j) & i) ? 1 : 0;  // Tuniery operator
        // Print k.
        printf("%d", k);
        
    }
}

// Standard main signature.
int main(int argc, char *argv[]) {

    // Set i to a literal value.
    unsigned int i = 0xffffffff; //1; //0xf1; //241 //4294967295

    // What we're printing.
    printf("Original:  ");
    // Print i in binary.
    bin_print(i);
    // End line.
    printf("\t%x\t%d\n", i, i);
    

    for (int j = 0; j < 40; j++) {
        // What the operation is. 
        printf("%3u << %2d: ", i, j);
        // i shifted left j times
        bin_print(i << j);
        // End line.
        printf("\n");
    }

    // Everything ok
    return 0;
}