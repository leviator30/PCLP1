#include <stdio.h>
#define MIE 1000
#define TREIZECI_SI_UNU 31

int putere(int n) {
    int p = 1;
    for ( int i = 0; i < n; i++ )
        p = p << 1;
    return p;
}

int main() {
    unsigned int inst = 0;
    unsigned int masca = 1;
    int N = 1, Dim = 1;
    char vector_caractere[MIE];

    scanf("%u", &inst);

    masca = masca << TREIZECI_SI_UNU;

    for ( int i = 0; i < 3; i++ )
        if (((masca >> i)&inst) != 0)
            N = N+putere(2-i);

    masca = masca>>3;

    for ( int i = 0; i < 2*N; i = i+2 ) {
            if (((masca >> i)&inst) == 0 && ((masca >> (i+1))&inst) == 0)
                vector_caractere[i/2]='+';
            if (((masca >> i)&inst) == 0 && ((masca >> (i+1))&inst) != 0)
                vector_caractere[i/2]='-';
            if (((masca >> i)&inst) != 0 && ((masca >> (i+1))&inst) == 0)
                vector_caractere[i/2]='*';
            if (((masca >> i)&inst) != 0 && ((masca >> (i+1))&inst) != 0)
                vector_caractere[i/2]='/';
            }

    masca = masca >> (2*N);

    for ( int i = 0; i < 4; i++ )
        if (((masca >> i)&inst) != 0)
            Dim = Dim+putere(3-i);

    printf("%d ", N);
    for ( int i = 0; i < N; i++ )
        printf("%c ", vector_caractere[i]);
    printf("%d\n", Dim);

    return 0;
}
