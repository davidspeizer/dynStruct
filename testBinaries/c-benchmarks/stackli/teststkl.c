#include <stdio.h>
#include "stackli.h"
#include "print.h"

main( )
{
    Stack S;
    int i;

    S = CreateStack( );
    for( i = 0; i < 10; i++ )
        Push( i, S );

    while( !IsEmpty( S ) )
    {
        print32( Top( S ) );
        prints( "\n" );
        //printf( "%d\n", Top( S ) );
        Pop( S );
    }

    DisposeStack( S );
    return 0;
}
