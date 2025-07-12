#include "redblack.h"
#include <stdio.h>
#include "print.h"

//#define N 800
#define N 50

main( )
{
    RedBlackTree T;
    Position P, *NullNode = malloc(sizeof(Position));
    int i;
    int j = 0;
    *NullNode = NULL;

    T = Initialize( NullNode );
    T = MakeEmpty( T, *NullNode );

    for( i = 0; i < N; i++, j = ( j + 7 ) % N )
        T = Insert( j, T, *NullNode );
    prints( "Inserts are complete\n" );



    for( i = 0; i < N; i++ )
        if( ( P = Find( i, T, *NullNode ) ) == NULL || Retrieve( P ) != i ) {
            prints( "Error at " );
            print32( i );
            prints( "\n" );
            //printf( "Error at %d\n", i );
	}


    prints( "Min is " );
    print32( Retrieve( FindMin( T, *NullNode ) ) );
    prints( ", Max is " );
    print32( Retrieve( FindMax( T, *NullNode ) ) );
    prints( "\n" );
    //printf( "Min is %d, Max is %d\n", Retrieve( FindMin( T, NullNode ) ), Retrieve( FindMax( T, NullNode ) ) );

    return 0;
}
