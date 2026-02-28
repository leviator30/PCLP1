#include "./utils.h"
#define CINCI 5
#define SAPTE 7
#define TREI 3
#define MIE 1000
void SolveTask5(void *info, int nr_avioane, int T, int nr_pct_coord, int *X, int *Y, int N) {
    // TODO(student) : Stuff
    short linie = 0, coloana = 0;
    char directia = 0, tip = 0;
    char* pointer = info;
    int viteza = 0, mat[MIE][MIE], mat_obstacole[MIE][MIE], v[MIE];

        for ( int i = 0; i < nr_pct_coord; i++ )
            mat_obstacole[X[i]][Y[i]] = '@';


        for ( int i = 0; i < N; i++ )
            for ( int j = 0; j < N; j++ )
                if ( mat_obstacole[i][j] != '@' )
                    mat_obstacole[i][j] = '.';

        for ( int i = 0; i <= T; i++ )
            v[i] = 0;

    for ( int i = 0; i < nr_avioane; i++ ) {
        linie = *(short*)pointer;
        pointer = pointer+sizeof(short);

        coloana = *(short*)pointer;
        pointer = pointer+sizeof(short);

        directia = *(char*)pointer;
        pointer = pointer+sizeof(char);

        tip = *(char*)pointer;
        pointer = pointer+sizeof(char);

        pointer = pointer+3*sizeof(char);

        viteza = *(int*)pointer;
        pointer = pointer+sizeof(int);

        for ( int l = 0; l <= T; l++ ) {
            int contor = 0;
            int conditie = 0;

            for ( int i = 0; i < N; i++ )
                for ( int j = 0; j < N; j++ ) {
                    if ( linie == i && coloana == j ) {
                        mat[i][j] = '*';
                        if ( tip == '1' ) {
                            if ( directia == 'N' ) {
                                if ( mat_obstacole[i-l*viteza][j] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < CINCI; k++ ) {
                                    mat[i+1][j-2+k] = '*';
                                    if (mat_obstacole[i+1-l*viteza][j-2+k] == '@' )
                                        conditie = 1;
                                    }
                                mat[i+2][j] = '*';
                                if ( mat_obstacole[i+2-l*viteza][j] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < TREI; k++ ) {
                                    mat[i+3][j-1+k] = '*';
                                    if ( mat_obstacole[i+3-l*viteza][j-1+k] == '@' )
                                        conditie = 1;
                                    }
                                }
                            if ( directia == 'S' ) {
                                if ( mat_obstacole[i+l*viteza][j] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < CINCI; k++ ) {
                                    mat[i-1][j-2+k] = '*';
                                    if ( mat_obstacole[i-1+l*viteza][j-2+k] == '@' )
                                        conditie = 1;
                                    }
                                mat[i-2][j] = '*';
                                if ( mat_obstacole[i-2+l*viteza][j] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < TREI; k++ ) {
                                    mat[i-3][j-1+k] = '*';
                                    if ( mat_obstacole[i-3+l*viteza][j-1+k] == '@' )
                                        conditie = 1;
                                    }
                                }
                            if ( directia == 'E' ) {
                                if ( mat_obstacole[i][j+l*viteza] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < CINCI; k++ ) {
                                    mat[i-2+k][j-1] = '*';
                                    if ( mat_obstacole[i-2+k][j-1+l*viteza] == '@' )
                                        conditie = 1;
                                    }
                                if ( mat_obstacole[i][j-2+l*viteza] == '@' )
                                    conditie = 1;
                                mat[i][j-2] = '*';
                                for ( int k = 0; k < TREI; k++ ) {
                                    mat[i-1+k][j-3] = '*';
                                    if ( mat_obstacole[i-1+k][j-3+l*viteza] == '@' )
                                        conditie = 1;
                                    }
                                }
                            if ( directia == 'W' ) {
                                if ( mat_obstacole[i][j-l*viteza] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < CINCI; k++ ) {
                                    mat[i-2+k][j+1] = '*';
                                    if ( mat_obstacole[i-2+k][j+1-l*viteza] == '@' )
                                        conditie = 1;
                                    }
                                if ( mat_obstacole[i][j+2-l*viteza] == '@' )
                                    conditie = 1;
                                mat[i][j+2] = '*';
                                for ( int k = 0; k < TREI; k++ ) {
                                    mat[i-1+k][j+3] = '*';
                                    if ( mat_obstacole[i-1+k][j+3-l*viteza] == '@' )
                                        conditie = 1;
                                    }
                                }
                            }
                        if ( tip == '2' ) {
                            if ( directia == 'N' ) {
                                if ( mat_obstacole[i-l*viteza][j] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < TREI; k++ ) {
                                    mat[i+1][j-1+k] = '*';
                                    if ( mat_obstacole[i+1-l*viteza][j-1+k] == '@' )
                                        conditie = 1;
                                    }
                                for ( int k = 0; k < SAPTE; k++ ) {
                                    mat[i+2][j-3+k]='*';
                                    if ( mat_obstacole[i+2-l*viteza][j-3+k] == '@' )
                                        conditie = 1;
                                    }
                                if ( mat_obstacole[i+3-l*viteza][j] == '@' )
                                    conditie = 1;
                                mat[i+3][j] = '*';
                                for ( int k = 0; k < CINCI; k++ ) {
                                    mat[i+4][j-2+k] = '*';
                                    if ( mat_obstacole[i+4-l*viteza][j-2+k] == '@' )
                                        conditie = 1;
                                    }
                                }
                            if ( directia == 'S' ) {
                                if ( mat_obstacole[i+l*viteza][j] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < TREI; k++ ) {
                                    mat[i-1][j-1+k] = '*';
                                    if ( mat_obstacole[i-1+l*viteza][j-1+k] == '@' )
                                        conditie = 1;
                                    }
                                for ( int k = 0; k < SAPTE; k++ ) {
                                    mat[i-2][j-3+k] = '*';
                                    if ( mat_obstacole[i-2+l*viteza][j-3+k] == '@' )
                                        conditie = 1;
                                    }
                                if ( mat_obstacole[i-3+l*viteza][j] == '@' )
                                    conditie = 1;
                                mat[i-3][j] = '*';
                                for ( int k = 0; k < CINCI; k++ ) {
                                    mat[i-4][j-2+k] = '*';
                                    if ( mat_obstacole[i-4+l*viteza][j-2+k] == '@' )
                                        conditie = 1;
                                    }
                                }
                            if ( directia == 'E' ) {
                                if ( mat_obstacole[i][j+l*viteza] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < TREI; k++ ) {
                                    mat[i-1+k][j-1] = '*';
                                    if ( mat_obstacole[i-1+k][j-1+l*viteza] == '@' )
                                        conditie = 1;
                                    }
                                for ( int k = 0; k < SAPTE; k++ ) {
                                    mat[i-3+k][j-2] = '*';
                                    if ( mat_obstacole[i-3+k][j-2+l*viteza] == '@' )
                                        conditie = 1;
                                    }
                                if ( mat_obstacole[i][j-3+l*viteza] == '@' )
                                    conditie = 1;
                                mat[i][j-3]='*';
                                for ( int k = 0; k < CINCI; k++ ) {
                                    mat[i-2+k][j-4] = '*';
                                    if ( mat_obstacole[i-2+k][j-4+l*viteza] == '@' )
                                        conditie = 1;
                                    }
                                }
                            if ( directia == 'W' ) {
                                if ( mat_obstacole[i][j-l*viteza] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < TREI; k++ ) {
                                    if ( mat_obstacole[i-1+k][j+1-l*viteza] == '@' )
                                        conditie = 1;
                                    mat[i-1+k][j+1] = '*';
                                    }
                                for ( int k = 0; k < SAPTE; k++ ) {
                                    mat[i-3+k][j+2] = '*';
                                    if ( mat_obstacole[i-3+k][j+2-l*viteza] == '@' )
                                        conditie = 1;
                                    }
                                mat[i][j+3] = '*';
                                if ( mat_obstacole[i][j+3-l*viteza] == '@' )
                                    conditie = 1;
                                for ( int k = 0; k < CINCI; k++ ) {
                                    mat[i-2+k][j+4] = '*';
                                    if ( mat_obstacole[i-2+k][j+4-l*viteza] == '@' )
                                        conditie = 1;
                                    }
                                }
                            }
                        }
                    }
            if ( conditie == 1 )
                v[l]++;
            }
        }
        for ( int i = 0; i <= T; i++ )
            printf("%d: %d\n", i, v[i]);
    }
