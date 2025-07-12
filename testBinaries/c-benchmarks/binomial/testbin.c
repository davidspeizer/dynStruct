#include "binomial.h"
#include <stdio.h>
#include "print.h"

#define MaxSize (1000)
//#define MaxSize (12000)

main( )
{
    BinQueue H;
    int i, j;
    ElementType AnItem;

    H = Initialize( );
    //prints("Inserting... ");
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize )
    {
 /*     printf( "Inserting %d\n", j );
 */     H = Insert( j, H );
       // print32(i);
       // prints(" ");
    }
    prints("Done inserting\n");
 #if 1
    j = 0;
    while( !IsEmpty( H ) )
    {
 /*     printf( "DeleteMin\n" );
        H = DeleteMin( &AnItem, H );
  */    if( DeleteMin( H ) != j++ ) {
            prints( "Error in DeleteMin, " );
            print32( j );
            prints( "\n" );
            //printf( "Error in DeleteMin, %d\n", j );
        }
    }
    if( j != MaxSize )
        prints( "Error in counting\n" );
    #endif
    prints( "Done...\n" );
    return 0;
}
