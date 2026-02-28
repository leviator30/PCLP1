#include <stdio.h>
#define SUTA 100
int main() {
    int i = 0, j = 0, n = 0;
    float vector_numere[SUTA];
    float rezultat = 0;
    char vector_operatori[SUTA];

    scanf("%d", &n);

    if ( n != 0 ) {
    for ( i = 0 ; i < n ; i++ )
        scanf("%f", &vector_numere[i]);

    if ( n != 1 )
    scanf("%s", vector_operatori);

    for ( i = 0 ; i < n-1 ; i++ ) {
        if ( vector_operatori[i] == '*' ) {
                vector_numere[i] = vector_numere[i]*vector_numere[i+1];

                for ( j = i+1 ; j < n ; j++ ) {
                        vector_numere[j] = vector_numere[j+1];
                        vector_operatori[j-1] = vector_operatori[j];
                    }
                n--; i--;
            }
        if ( vector_operatori[i] == '/' ) {
                vector_numere[i] = vector_numere[i]/vector_numere[i+1];

                for ( j=i+1 ; j < n ; j++ ) {
                        vector_numere[j] = vector_numere[j+1];
                        vector_operatori[j-1] = vector_operatori[j];
                    }
                n--; i--;
            }
    }

    for ( i=0 ; i < n ; i++ )
        if ( vector_operatori[i] == '#' ) {
        vector_numere[i] = (vector_numere[i]+vector_numere[i+1])*(vector_numere[i]+vector_numere[i+1]);
            for ( j = i+1 ; j < n ; j++ ) {
                    vector_numere[j] = vector_numere[j+1];
                    vector_operatori[j-1] = vector_operatori[j];
                }
            n--; i--;
        }

    rezultat = vector_numere[0];

    for ( i = 0 ; i < n-1 ; i++ ) {
            if ( vector_operatori[i] == '+' )
                rezultat = rezultat+vector_numere[i+1];
            else
                rezultat = rezultat-vector_numere[i+1];
        }
    }
    printf("%f\n", rezultat);
    return 0;
}
