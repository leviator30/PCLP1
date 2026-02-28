#include "./utils.h"
#define TREI 3
#define CINCI 5
#define SAPTE 7
void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    // TODO(student) : Stuff
    short linie = 0, coloana = 0;
    char directia = 0, tip = 0;
    char*pointer = info;

    for ( int i = 0; i < nr_avioane; i++ ) {
        linie = *(short*)pointer;
        pointer = pointer+sizeof(short);

        coloana = *(short*)pointer;
        pointer = pointer+sizeof(short);

        directia = *(char*)pointer;
        pointer = pointer+sizeof(char);

        tip = *(char*)pointer;
        pointer = pointer+sizeof(char);

        pointer = pointer+3*sizeof(char)+sizeof(int);

        for ( int i = 0; i < N; i++ )
            for ( int j = 0; j < N; j++ ) {
                    if ( linie == i && coloana == j ) {
                            mat[i][j]='*';
                            if ( tip == '1' ) {
                                    if ( directia == 'N' ) {
                                            for ( int k = 0; k < CINCI; k++ )
                                                mat[i+1][j-2+k]='*';
                                            mat[i+2][j]='*';
                                            for ( int k = 0; k < TREI; k++ )
                                                mat[i+3][j-1+k]='*';
                                        }
                                    if ( directia == 'S' ) {
                                            for ( int k = 0; k < CINCI; k++ )
                                                mat[i-1][j-2+k]='*';
                                            mat[i-2][j]='*';
                                            for ( int k = 0; k < TREI; k++ )
                                                mat[i-3][j-1+k]='*';
                                        }
                                    if ( directia == 'E' ) {
                                            for ( int k = 0; k < CINCI; k++ )
                                                mat[i-2+k][j-1]='*';
                                            mat[i][j-2]='*';
                                            for ( int k = 0; k < TREI; k++ )
                                                mat[i-1+k][j-3]='*';
                                        }
                                    if ( directia == 'W' ) {
                                            for ( int k = 0; k < CINCI; k++ )
                                                mat[i-2+k][j+1]='*';
                                            mat[i][j+2]='*';
                                            for ( int k = 0; k < TREI; k++ )
                                                mat[i-1+k][j+3]='*';
                                        }
                                }
                                if ( tip == '2' ) {
                                    if ( directia == 'N' ) {
                                            for ( int k = 0; k < TREI; k++ )
                                                mat[i+1][j-1+k]='*';
                                            for ( int k = 0; k < SAPTE; k++ )
                                                mat[i+2][j-3+k]='*';
                                            mat[i+3][j]='*';
                                            for ( int k = 0; k < CINCI; k++ )
                                                mat[i+4][j-2+k]='*';
                                        }
                                    if ( directia == 'S' ) {
                                            for ( int k = 0; k < TREI; k++ )
                                                mat[i-1][j-1+k]='*';
                                            for ( int k = 0; k < SAPTE; k++ )
                                                mat[i-2][j-3+k]='*';
                                            mat[i-3][j]='*';
                                            for ( int k = 0; k < CINCI; k++ )
                                                mat[i-4][j-2+k]='*';
                                        }
                                    if ( directia == 'E' ) {
                                            for ( int k = 0; k < TREI; k++ )
                                                mat[i-1+k][j-1]='*';
                                            for ( int k = 0; k < SAPTE; k++ )
                                                mat[i-3+k][j-2]='*';
                                            mat[i][j-3]='*';
                                            for ( int k = 0; k < CINCI; k++ )
                                                mat[i-2+k][j-4]='*';
                                        }
                                    if ( directia == 'W' ) {
                                            for ( int k = 0; k < TREI; k++ )
                                                mat[i-1+k][j+1]='*';
                                            for ( int k = 0; k < SAPTE; k++ )
                                                mat[i-3+k][j+2]='*';
                                            mat[i][j+3]='*';
                                            for ( int k = 0; k < CINCI; k++ )
                                                mat[i-2+k][j+4]='*';
                                        }
                                }
                        }
                }
    }

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            if ( mat[i][j] != '*' )mat[i][j]='.';
            printf("%c", mat[i][j]);
            }
        printf("\n");
    }
}
