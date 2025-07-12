#include "dsl.h"
#include <stdio.h>
#include "print.h"

//#define N 800
#define N 10

main( )
{
    SkipList T;
    Position P, *Bottom = malloc(sizeof(Position)), *Tail = malloc(sizeof(Position));
    int i;
    int j = 0;
    *Bottom = NULL;
    *Tail = NULL;

    T = Initialize( Bottom, Tail);
    T = MakeEmpty( T, *Bottom, *Tail );

    for( i = 0; i < N; i++, j = ( j + 7 ) % N )
        T = Insert( j, T, *Bottom, *Tail );
    prints( "Inserts are complete\n" );


    for( i = 0; i < N; i++ )
        if( ( P = Find( i, T, *Bottom ) ) == NULL || Retrieve( P ) != i ) {
            prints( "Error at " );
            print32( i );
            prints( "\n" );
            //printf( "Error at %d\n", i );
	}

    prints( "Min is " );
    print32( Retrieve( FindMin( T, *Bottom ) ) );
    prints( ", Max is " );
    print32( Retrieve( FindMax( T, *Bottom, *Tail ) ) );
    prints( "\n");
    //printf( "Min is %d, Max is %d\n", Retrieve( FindMin( T, Bottom ) ), Retrieve( FindMax( T, Bottom, Tail ) ) );

    return 0;
}
