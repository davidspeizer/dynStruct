#include "leftheap.h"
#include <stdio.h>
#include "print.h"

//#define MaxSize 5000
#define MaxSize 1000

main( )
{
    PriorityQueue H;
    int i, j;

    H = Initialize( );
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+17)%MaxSize )
        Insert( j, H );

    j = 0;
    while( !IsEmpty( H ) )
        if( FindMin( H ) != j++ ) {
            prints( "Error in DeleteMin, " );
            print32( j );
            prints( "\n" );
            //printf( "Error in DeleteMin, %d\n", j );
	}
        else
            H = DeleteMin1( H );
    prints( "Done...\n" );
    return 0;
}
