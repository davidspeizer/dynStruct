#include <stdio.h>
#include "list.h"
#include "print.h"

void
PrintList( const List L )
{
    Position P = Header( L );

    if( IsEmpty( L ) )
        prints( "Empty list\n" );
    else
    {
        do
        {
            P = Advance( P );
            print32( Retrieve( P ) );
            prints( " " );
            //printf( "%d ", Retrieve( P ) );
        } while( !IsLast( P, L ) );
        prints( "\n" );
    }
}

main( )
{
    List L;
    Position P;
    int i;

    L = MakeEmpty( NULL );
    P = Header( L );
    PrintList( L );

    for( i = 0; i < 10; i++ )
    {
        Insert( i, L, P );
        PrintList( L );
        P = Advance( P );
    }
    for( i = 0; i < 10; i+= 2 )
        Delete( i, L );

    for( i = 0; i < 10; i++ )
        if( ( i % 2 == 0 ) == ( Find( i, L ) != NULL ) )
            prints( "Find fails\n" );

    prints( "Finished deletions\n" );

    PrintList( L );

    DeleteList( L );

    return 0;
}
