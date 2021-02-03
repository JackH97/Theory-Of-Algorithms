#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 0xF1; // 11110001

    printf("Hex: %d\n", i);
    printf("Hex: %x\n", i);
    printf("\n");
    printf("Size of i: %d\n", sizeof(i));
    printf("Size of int: %d\n", sizeof(int));
    printf("Size of char: %d\n", sizeof(char));
    printf("\n");
    char c = 241;
    printf("c in Char is: %c\n", c);
    printf("c in int is: %d\n", c);
    printf("\n");
    int j = 1000000000;
    printf("j in int is: %d\n", j);
    printf("j in Char is: %c\n", j);
    printf("j in int from char is: %d\n",(char) j);

    return 0;
}