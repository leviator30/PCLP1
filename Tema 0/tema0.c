#include <stdio.h>
#define SAPTE 7
#define UNSPREZECE 11
int main() {
    unsigned i = 0 , n = 0;
    printf("Introduceti valoarea numarului natural N:\n");
    scanf("%d", &n);
    if ( n !=0 ) {
        for ( i = 1 ; i < n ; i++ ) {
            if ( i%SAPTE == 0 && i%UNSPREZECE == 0 )
                printf("TrickOrTreat ");
            else if ( i%SAPTE == 0 )
                printf("Trick ");
            else if ( i%UNSPREZECE == 0 )
                printf("Treat ");
            else
                printf("%d ", i);
        }

        if ( n%SAPTE == 0 && n%UNSPREZECE == 0 )
            printf("TrickOrTreat");
        else if ( n%SAPTE == 0 )
            printf("Trick");
        else if ( n%UNSPREZECE == 0 )
            printf("Treat");
        else
            printf("%d", i);
    }
    return 0;
}
