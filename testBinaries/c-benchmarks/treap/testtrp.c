#include "treap.h"
#include <stdio.h>
#include "print.h"

#define NumItems 10

main( )
{

    Treap T;
    Position P;
    Position NullNode;
    int i;
    int j = 0;

    NullNode = Initialize( );
    T = NullNode;
    T = MakeEmpty( T, NullNode );
    for( i = 0; i < NumItems; i++, j = ( j + 7 ) % NumItems )
        T = Insert( j, T, NullNode );
    for( i = 0; i < NumItems; i++ )
        if( ( P = Find( i, T, NullNode ) ) == NullNode || Retrieve( P ) != i ) {
            prints( "Error1 at " );
            print32( i );
            prints( "\n" );
            //printf( "Error1 at %d\n", i );
	}

    for( i = 0; i < NumItems; i += 2 )
        T = Remove( i, T, NullNode );

    for( i = 1; i < NumItems; i += 2 )
        if( ( P = Find( i, T, NullNode) ) == NullNode || Retrieve( P ) != i ) {
           prints( "Error2 at " );
           print32(  i );
           prints( "\n" );
           //printf( "Error2 at %d\n", i );
	}

    for( i = 0; i < NumItems; i += 2 )
        if( ( P = Find( i, T, NullNode ) ) != NullNode ) {
            prints( "Error3 at " );
            print32(  i );
            prints( "\n" );
            //printf( "Error3 at %d\n", i );
	}
    prints( "Min is " );
    print32( Retrieve( FindMin( T, NullNode ) ));
    prints( ", Max is " );
    print32(  Retrieve( FindMax( T, NullNode ) ) );
    prints( "\n");
    //printf( "Min is %d, Max is %d\n", Retrieve( FindMin( T, NullNode ) ), Retrieve( FindMax( T, NullNode ) ) );

    return 0;
}
