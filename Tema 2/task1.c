#include "./utils.h"

void SolveTask1(void *info, int nr_avioane) {
    // TODO(student) : Stuff
    short linie = 0, coloana = 0;
    char directie = 0, tip = 0, cod[3];
    int viteza = 0;
    char* pointer = info;

    for ( int i = 0; i < nr_avioane; i++ ) {
    linie = *(short*)pointer;
    pointer = pointer+sizeof(short);

    coloana = *(short*)pointer;
    pointer = pointer+sizeof(short);

    directie = *(char*)pointer;
    pointer = pointer+sizeof(char);

    tip = *(char*)pointer;
    pointer = pointer+sizeof(char);

    cod[0] = *(char*)pointer;
    pointer = pointer+sizeof(char);

    cod[1] = *(char*)pointer;
    pointer = pointer+sizeof(char);

    cod[2] = *(char*)pointer;
    pointer = pointer+sizeof(char);

    viteza = *(int*)pointer;
    pointer = pointer+sizeof(int);

    printf("(%hi, %hi) \n", linie, coloana);
    printf("%c \n", directie);
    printf("%c%c%c%c \n", tip, cod[0], cod[1], cod[2]);
    printf("%d \n", viteza);
    printf("\n");
}
}
