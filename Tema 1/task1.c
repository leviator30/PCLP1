#include <stdio.h>
#define SUTA 100
int main() {
    int i = 0, n = 0;
    float vector_numere[SUTA];
    char vector_operatori[SUTA];
    float rezultat = 0;

    scanf("%d", &n);

    if ( n != 0 ) {
    for ( i = 0 ; i < n ; i++ )
        scanf("%f", &vector_numere[i]);

    if ( n != 1 )
        scanf("%s", vector_operatori);

    rezultat = vector_numere[0];

    for ( i=0 ; i < n-1 ; i++ ) {
            if ( vector_operatori[i] == '+' )
                rezultat = rezultat+vector_numere[i+1];
            else if ( vector_operatori[i] == '-' )
                rezultat = rezultat-vector_numere[i+1];
            else if ( vector_operatori[i] == '*' )
                rezultat = rezultat*vector_numere[i+1];
            else if ( vector_operatori[i] == '/' )
                rezultat = rezultat/vector_numere[i+1];
        }
    }
    printf("%f\n", rezultat);
    return 0;
}
