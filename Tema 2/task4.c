#include "./utils.h"
#define TREI 3
#define CINCI 5
#define SAPTE 7
#define MIE 1000
void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N) {
    // TODO(student) : Stuff
    short linie = 0, coloana = 0;
    char directia = 0, tip = 0;
    char* pointer = info;
    int mat[MIE][MIE], mat_obstacole[MIE][MIE];
    int contor = 0;

    for ( int i = 0; i < nr_obstacole; i++ )
        mat_obstacole[x[i]][y[i]]='@';

    for ( int i=0; i < nr_avioane; i++ ) {
        linie = *(short*)pointer;
        pointer = pointer+sizeof(short);

        coloana = *(short*)pointer;
        pointer = pointer+sizeof(short);

        directia = *(char*)pointer;
        pointer = pointer+sizeof(char);

        tip = *(char*)pointer;
        pointer = pointer+sizeof(char);

        pointer = pointer+3*sizeof(char)+sizeof(int);

        int conditie = 0;

        for ( int i = 0; i < N; i++ )
            for ( int j = 0; j < N; j++ )
                if ( linie == i && coloana == j ) {
                    if ( mat_obstacole[i][j] == '@' ) {
                        conditie = 1;
                        }
                    mat[i][j] = '*';
                    if ( tip == '1' ) {
                        if ( directia == 'N' ) {
                            for ( int k = 0; k < CINCI; k++ ) {
                                if ( mat_obstacole[i+1][j-2+k] == '@')
                                    conditie = 1;
                                mat[i+1][j-2+k] = '*';
                                }
                            if ( mat_obstacole[i+2][j] == '@')
                                conditie = 1;
                            mat[i+2][j] = '*';
                            for ( int k = 0; k < TREI; k++ ) {
                                if ( mat_obstacole[i+3][j-1+k] == '@' )
                                    conditie = 1;
                                mat[i+3][j-1+k] = '*';
                                }
                            if ( mat_obstacole[i+2][j-1] == '@' || mat_obstacole[i+2][j+1] == '@' )
                                conditie = 1;
                            for ( int k = 0; k <= i; k++ )
                                for ( int l = j-2; l <= j+2; l++ )
                                    if ( mat_obstacole[k][l] == '@' )
                                        conditie = 1;
                            }
                        if ( directia == 'S' ) {
                            for ( int k = 0; k < CINCI; k++ ) {
                                if ( mat_obstacole[i-1][j-2+k] == '@' )
                                    conditie = 1;
                                mat[i-1][j-2+k]='*';
                                }
                            if ( mat_obstacole[i-2][j] == '@' )
                                conditie = 1;
                            mat[i-2][j] = '*';
                            for ( int k = 0; k < TREI; k++ ) {
                                if ( mat_obstacole[i-3][j-1+k] == '@' )
                                    conditie = 1;
                                mat[i-3][j-1+k]='*';
                                }
                            if ( mat_obstacole[i-2][j-1] == '@' || mat_obstacole[i-2][j+1] == '@' )
                                conditie = 1;
                            for ( int k = N-1; k >= i; k-- )
                                for ( int l = j-2; l <= j+2; l++ )
                                    if ( mat_obstacole[k][l] == '@' )
                                        conditie = 1;
                            }
                        if ( directia == 'E' ) {
                            for ( int k = 0; k < CINCI; k++ ) {
                                if ( mat_obstacole[i-2+k][j-1] == '@' )
                                    conditie = 1;
                                mat[i-2+k][j-1] = '*';
                                }
                            if ( mat_obstacole[i][j-2] == '@' )
                                conditie = 1;
                            mat[i][j-2] = '*';
                            for ( int k = 0; k < TREI; k++ ) {
                                if ( mat_obstacole[i-1+k][j-3] == '@' )
                                    conditie = 1;
                                mat[i-1+k][j-3]='*';
                                }
                            if ( mat_obstacole[i-1][j-2] == '@' || mat_obstacole[i+1][j-2] == '@' )
                                conditie = 1;
                            for ( int k = i-2; k <= i+2; k++ )
                                for ( int l = j; l < N; l++ )
                                    if ( mat_obstacole[k][l] == '@' )
                                        conditie = 1;
                            }
                        if ( directia == 'W' ) {
                            for ( int k = 0; k < CINCI; k++ ) {
                                if ( mat_obstacole[i-2+k][j+1] == '@' )
                                    conditie = 1;
                                mat[i-2+k][j+1]='*';
                                }
                            if ( mat_obstacole[i][j+2] == '@' )
                                conditie = 1;
                            mat[i][j+2]='*';
                            for ( int k = 0; k < TREI; k++ ) {
                                if ( mat_obstacole[i-1+k][j+3] == '@' )
                                    conditie = 1;
                                mat[i-1+k][j+3]='*';
                                }
                            if ( mat_obstacole[i-1][j+2] == '@' || mat_obstacole[i+1][j+2] == '@' )
                                conditie = 1;
                            for ( int k = i-2; k <= i+2; k++ )
                                for ( int l = 0; l <= j; l++ )
                                    if ( mat_obstacole[k][l] == '@' )
                                        conditie = 1;
                            }
                        }
                    if ( tip == '2' ) {
                        if ( directia == 'N' ) {
                            for ( int k = 0; k < TREI; k++ ) {
                                if ( mat_obstacole[i+1][j-1+k] == '@' )
                                    conditie = 1;
                                mat[i+1][j-1+k] = '*';
                                }
                            for ( int k = 0; k < SAPTE; k++ ) {
                                if ( mat_obstacole[i+2][j-3+k] == '@' )
                                    conditie = 1;
                                mat[i+2][j-3+k] = '*';
                                }
                            if ( mat_obstacole[i+3][j] == '@' )
                                conditie = 1;
                            mat[i+3][j] = '*';
                            for ( int k = 0; k < CINCI; k++ ) {
                                if ( mat_obstacole[i+4][j-2+k] == '@' )
                                    conditie = 1;
                                mat[i+4][j-2+k] = '*';
                                }
                            if ( mat_obstacole[i+3][j-2] == '@' || mat_obstacole[i+3][j-1] == '@' )
                                conditie = 1;
                            if ( mat_obstacole[i+3][j+1] == '@' || mat_obstacole[i+3][j+2] == '@' )
                                conditie = 1;
                            for ( int k = 0; k <= i+2; k++ )
                                for ( int l = j-3; l <= j+3; l++ )
                                    if ( mat_obstacole[k][l] == '@' )
                                        conditie = 1;
                            }
                        if ( directia == 'S' ) {
                            for ( int k = 0; k < TREI; k++ ) {
                                if ( mat_obstacole[i-1][j-1+k] == '@' )
                                    conditie = 1;
                                mat[i-1][j-1+k] = '*';
                                }
                            for ( int k = 0; k < SAPTE; k++ ) {
                                if ( mat_obstacole[i-2][j-3+k] == '@' )
                                    conditie = 1;
                                mat[i-2][j-3+k] = '*';
                                }
                            if ( mat_obstacole[i-3][j] == '@' )
                                conditie = 1;
                            mat[i-3][j] = '*';
                            for ( int k = 0; k < CINCI; k++ ) {
                                if ( mat_obstacole[i-4][j-2+k] == '@' )
                                    conditie = 1;
                                mat[i-4][j-2+k] = '*';
                                }
                            if ( mat_obstacole[i-3][j-2] == '@' || mat_obstacole[i-3][j-1] == '@' )
                                conditie = 1;
                            if ( mat_obstacole[i-3][j+1] == '@' || mat_obstacole[i-3][j+2] == '@' )
                                conditie = 1;
                            for ( int k = N-1; k >= i-1; k-- )
                                for ( int l = j-3; l <= j+3; l++ )
                                    if ( mat_obstacole[k][l] == '@' )
                                        conditie = 1;
                            }
                        if ( directia == 'E' ) {
                            for ( int k = 0; k < TREI; k++ ) {
                                if ( mat_obstacole[i-1+k][j-1] == '@' )
                                    conditie = 1;
                                mat[i-1+k][j-1] = '*';
                                }
                            for ( int k = 0; k < SAPTE; k++ ) {
                                if ( mat_obstacole[i-3+k][j-2] == '@' )
                                    conditie = 1;
                                mat[i-3+k][j-2] = '*';
                                }
                            if ( mat_obstacole[i][j-3] == '@' )
                                conditie = 1;
                            mat[i][j-3] = '*';
                            for ( int k = 0; k < CINCI; k++ ) {
                                if ( mat_obstacole[i-2+k][j-4] == '@' )
                                    conditie = 1;
                                mat[i-2+k][j-4] = '*';
                                }
                            if ( mat_obstacole[i-2][j-3] == '@' || mat_obstacole[i-1][j-3] == '@' )
                                conditie = 1;
                            if ( mat_obstacole[i+1][j-3] == '@' || mat_obstacole[i+2][j-3] == '@' )
                                conditie = 1;
                            for ( int k = i-3; k <= i+3; k++ )
                                for ( int l = j-1; l < N; l++ )
                                    if ( mat_obstacole[k][l] == '@' )
                                        conditie = 1;
                            }
                        if ( directia == 'W' ) {
                            for ( int k = 0; k < TREI; k++ ) {
                                if ( mat_obstacole[i-1+k][j+1] == '@' )
                                    conditie = 1;
                                mat[i-1+k][j+1] = '*';
                                }
                            for ( int k = 0; k < SAPTE; k++ ) {
                                if ( mat_obstacole[i-3+k][j+2] == '@' )
                                    conditie = 1;
                                mat[i-3+k][j+2] = '*';
                                }
                            if ( mat_obstacole[i][j+3] == '@' )
                                conditie = 1;
                            mat[i][j+3] = '*';
                            for ( int k = 0; k < CINCI; k++ ) {
                                if ( mat_obstacole[i-2+k][j+4] == '@' )
                                    conditie = 1;
                                mat[i-2+k][j+4] = '*';
                                }
                            if ( mat_obstacole[i-2][j+3] == '@' || mat_obstacole[i-1][j+3] == '@' )
                                conditie = 1;
                            if ( mat_obstacole[i+1][j+3] == '@' || mat_obstacole[i+2][j+3] == '@' )
                                conditie = 1;
                            for ( int k = i-3; k <= i+3; k++ )
                                for ( int l = 0; l <= j+1; l++ )
                                    if ( mat_obstacole[k][l] == '@' )
                                        conditie = 1;
                            }
                        }
                    }
        if ( conditie == 1 )
            contor++;
        }
    printf("%d", nr_avioane-contor);
    }

