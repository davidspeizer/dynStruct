#include "pairheap.h"
#include <stdio.h>
#include "print.h"

void
sleep( int x )
{
    int i, j, k, m;

    for( i = 0; i < 10000; i++ )
        for( j = 0; j < 1000; j++ )
            for( k = 0; k < x; k++ )
                m++;
    prints( "Done sleeping!! " );
    print32( m );
    //printf( "Done sleeping!! %d", m );
}

//#define MaxSize 500
#define MaxSize 50

main( )
{
    PairHeap H;
    Position **P = malloc(sizeof(Position*) * MaxSize );
    int i, j;
    int *AnItem = malloc(sizeof(int));
    for (i = 0; i < MaxSize; i++) P[i] = malloc(sizeof(Position));

    H = Initialize( );
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize )
        H = Insert( j + MaxSize, H, P[ j ] );

    prints( "Done inserting\n" );

    for( i = 0, j = MaxSize / 2; i <MaxSize; i++, j=(j+51)%MaxSize )
        H = DecreaseKey( *P[ j ], MaxSize, H );

    j = 0;
    while( !IsEmpty( H ) )
    {
        if( ( ( H = DeleteMin( AnItem, H ) ), *AnItem ) != j++ ) {
            prints( "Error in DeleteMin, " );
            print32( j );
            prints( "\n" );
            //printf( "Error in DeleteMin, %d\n", j );
	}
    }
    prints( "Done...\n" );

    return 0;
}
