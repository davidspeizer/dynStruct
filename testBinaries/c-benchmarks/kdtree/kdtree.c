        #include <stdio.h>
        #include <stdlib.h>
        #include "fatal.h"
	#include "print.h"

        typedef int ElementType;
        typedef ElementType *ItemType;

        struct KdNode;
        typedef struct KdNode *Position;
        typedef struct KdNode *KdTree;

        struct KdNode
        {
            KdTree   Left;
            KdTree   Right;
            ItemType Data;
        };

/* START: fig12_43.txt */
        static KdTree
        RecursiveInsert( ItemType Item, KdTree T, int Level )
        {
            if( T == NULL )
            {
                T = malloc( sizeof( struct KdNode ) );
                if( T == NULL )
                    FatalError( "Out of space!!!" );
		T->Data = malloc(2 * sizeof(ElementType));
                if( T->Data == NULL )
                    FatalError( "Out of space!!!" );
                T->Left = T->Right = NULL;
                T->Data[ 0 ] = Item[ 0 ];
                T->Data[ 1 ] = Item[ 1 ];
            }
            else
            if( Item[ Level ] < T->Data[ Level ] )
                T->Left = RecursiveInsert( Item, T->Left, !Level );
            else
                T->Right = RecursiveInsert( Item, T->Right, !Level );
            return T;
        }

        KdTree
        Insert( ItemType Item, KdTree T )
        {
            return RecursiveInsert( Item, T, 0 );
        }
/* END */

/* START: fig12_44.txt */
        /* Print items satisfying */
        /* Low[ 0 ] <= Item[ 0 ] <= High[ 0 ] and */
        /* Low[ 1 ] <= Item[ 1 ] <= High[ 1 ] */

        static void
        RecPrintRange( ItemType Low, ItemType High,
                       KdTree T, int Level )
        {
            if( T != NULL )
            {
                if( Low[ 0 ] <= T->Data[ 0 ] &&
                                T->Data[ 0 ] <= High[ 0 ] &&
                                Low[ 1 ] <= T->Data[ 1 ] &&
                                T->Data[ 1 ] <= High[ 1 ] ) {
                    prints( "(" );
                    print32( T->Data[ 0 ] );
                    prints( "," );
                    print32( T->Data[ 1 ] );
                    prints( ")\n" );
                    //printf( "(%d,%d)\n", T->Data[ 0 ], T->Data[ 1 ] );
		}

                if( Low[ Level ] <= T->Data[ Level ] )
                    RecPrintRange( Low, High, T->Left, !Level );
                if( High[ Level ] >= T->Data[ Level ] )
                    RecPrintRange( Low, High, T->Right, !Level );
            }
        }

        void
        PrintRange( ItemType Low, ItemType High, KdTree T )
        {
            RecPrintRange( Low, High, T, 0 );
        }
/* END */

main( )
{
    KdTree T;
    ItemType It = malloc(2 * sizeof(int)), L = malloc(2 * sizeof(int)), H = malloc(2 * sizeof(int));
    int i;

    prints( "Starting program\n" );

    T = NULL;
    for( i = 300; i < 370; i++ )
    {
        It[ 0 ] = i; It[ 1 ] = 2500 - i;
        T = Insert( It, T );
    }

    prints( "Insertions complete\n" );

    i = 1;
    L[ 0 ] = 70; L[ 1 ] = 2186; H[ 0 ] = 1200; H[ 1 ] = 2200;
    PrintRange( L, H, T );

    prints( "Done...\n" ) ;
    return 0;
}

