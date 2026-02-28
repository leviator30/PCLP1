#include <stdio.h>
#define MIE 1000
#define TREIZECI_SI_UNU 31
#define SAISPREZECE 16
#define CINCISPREZECE 15

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
                vector_caractere[i/2] = '+';
            if (((masca >> i)&inst) == 0 && ((masca >> (i+1))&inst) != 0)
                vector_caractere[i/2] = '-';
            if (((masca >> i)&inst) != 0 && ((masca >> (i+1))&inst) == 0)
                vector_caractere[i/2] = '*';
            if (((masca >> i)&inst) != 0 && ((masca >> (i+1))&inst) != 0)
                vector_caractere[i/2] = '/';
            }

    masca = masca >> (2*N);

    for ( int i = 0; i < 4; i++ )
        if (((masca >> i)&inst) != 0)
            Dim = Dim+putere(3-i);

    int numar_unsigned_shorturi = ((N+1)*Dim)/SAISPREZECE;
    if (((N+1)*Dim)%SAISPREZECE != 0)
        numar_unsigned_shorturi++;
    int contor = 0, vector_numere[MIE], capat = 0;
    __int16_t numar[MIE];

    for ( int i = 0; i < N+1; i++ )
        vector_numere[i] = 0;

    for ( int p = 0; p < numar_unsigned_shorturi; p++ )
        scanf("%hu", &numar[p]);

    for ( int p = 0; p < numar_unsigned_shorturi; p++ ) {
        if (capat != 0) {
            masca = 1 << CINCISPREZECE;
            for ( int i = 0; i < capat; i++ ) {
                if ((masca&numar[p]) != 0)
                vector_numere[contor] = vector_numere[contor]+putere(capat-i-1);
            masca = masca >> 1;
            }
            contor++;
            }

    masca = 1 << (CINCISPREZECE-capat);
    for ( int i = capat; i < capat+((SAISPREZECE-capat)/Dim)*Dim; i = i+Dim ) {
        for ( int j = i; j < i+Dim; j++ ) {
            if ((masca&numar[p]) != 0)
            vector_numere[contor] = vector_numere[contor]+putere(i+Dim-j-1);
        masca = masca >> 1;
        }
        contor++;
        }

    masca = 1 << CINCISPREZECE-(capat+((SAISPREZECE-capat)/Dim)*Dim);
    for ( int i = capat+((SAISPREZECE-capat)/Dim)*Dim; i < SAISPREZECE; i++ ) {
    if ((masca&numar[p]) != 0)
vector_numere[contor] += putere(Dim+capat+((SAISPREZECE-capat)/Dim)*Dim-i-1);
    masca = masca >> 1;
    }
    capat = Dim-(p+1)*(SAISPREZECE%Dim);
    }

    for ( int i = 0; i < N; i++ ) {
        if (vector_caractere[i] == '*') {
            vector_numere[i] = vector_numere[i]*vector_numere[i+1];
            for ( int j = i+1; j < N; j++ ) {
                vector_numere[j] = vector_numere[j+1];
                vector_caractere[j-1] = vector_caractere[j];
                }
            N--; i--;
            }
        if (vector_caractere[i] == '/') {
            vector_numere[i] = vector_numere[i]/vector_numere[i+1];
            for ( int j = i+1; j < N; j++ ) {
                vector_numere[j] = vector_numere[j+1];
                vector_caractere[j-1] = vector_caractere[j];
                }
            N--; i--;
            }
        }

    int rezultat = vector_numere[0];
    for ( int i = 0; i < N; i++ ) {
        if (vector_caractere[i] == '+')
            rezultat = rezultat+vector_numere[i+1];
        if (vector_caractere[i] == '-')
            rezultat = rezultat-vector_numere[i+1];
    }

    printf("%d\n", rezultat);
    return 0;
}
