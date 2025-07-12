#include "binheap.h"
#include <stdio.h>
#include "print.h"

#define MaxSize (1000)

main( )
{
    PriorityQueue H;
    int i, j;

    H = Initialize( MaxSize );
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize )
        Insert( j, H );

    j = 0;
    while( !IsEmpty( H ) )
        if( DeleteMin( H ) != j++ ) {
            prints( "Error in DeleteMin, " );
            print32( j );
            prints( "\n" );
            //printf( "Error in DeleteMin, %d\n", j );
	}
    prints( "Done...\n" );
    return 0;
}
