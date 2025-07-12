#include "splay.h"
#include <stdio.h>
#include "print.h"

#define NumItems 500


main( )
{
    SplayTree T;
    SplayTree P;
    Position NullNode, Header = malloc(sizeof(struct SplayNode));
    int i;
    int j = 0;

    NullNode = Initialize( );
    T = NullNode;
    T = MakeEmpty( T, NullNode );
    for( i = 0; i < NumItems; i++, j = ( j + 7 ) % NumItems )
        T = Insert( j, T, NullNode, Header );
  
    for( j = 0; j < 2; j++ )
        for( i = 0; i < NumItems; i++ )
        {
            T = Find( i, T, NullNode, Header );
            if( Retrieve( T ) != i ) {
                prints( "Error1 at " );
                print32( i );
                prints( "\n" );
                //printf( "Error1 at %d\n", i );
	    }
        }

    prints( "Entering remove\n" );

    for( i = 0; i < NumItems; i += 2 )
        T = Remove( i, T, NullNode, Header );

    for( i = 1; i < NumItems; i += 2 )
    {
        T = Find( i, T, NullNode, Header );
        if( Retrieve( T ) != i ) {
            prints( "Error2 at " );
            print32( i );
            prints( "\n" );
//            printf( "Error2 at %d\n", i );
	}
    }

    for( i = 0; i < NumItems; i += 2 )
    {
        T = Find( i, T, NullNode, Header );
        if( Retrieve( T ) == i ) {
            prints( "Error3 at " );
            print32( i );
            prints( "\n" );
            //printf( "Error3 at %d\n", i );
	}
    }

    prints( "Min is " );
    print32( Retrieve( T = FindMin( T, NullNode, Header ) ) );
    prints( "\n" );
    //printf( "Min is %d\n", Retrieve( T = FindMin( T, NullNode, Header ) ) );
    prints( "Max is " );
    print32( Retrieve( T = FindMax( T, NullNode, Header ) ) );
    prints( "\n" );
    //printf( "Max is %d\n", Retrieve( T = FindMax( T, NullNode, Header ) ) );

    return 0;
}
