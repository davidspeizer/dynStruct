#include "aatree.h"
#include <stdlib.h>
#include "fatal.h"
#include "print.h"
/* START: fig12_27.txt */

        struct AANode
        {
            ElementType Element;
            AATree      Left;
            AATree      Right;
            int         Level;
        };

        AATree
        Initialize( void )
        {
            /* Returned for failures */
            Position NullNode = NULL;  /* Needs more initialization */
            if( NullNode == NULL )
            {
                NullNode = malloc( sizeof( struct AANode ) );
                if( NullNode == NULL )
                    FatalError( "Out of space!!!" );
                NullNode->Left = NullNode->Right = NullNode;
                NullNode->Level = 0;
            }
            return NullNode;
        }
/* END */

        AATree
        MakeEmpty( AATree T, Position NullNode)
        {
            if( T != NullNode )
            {
                MakeEmpty( T->Left, NullNode );
                MakeEmpty( T->Right, NullNode );
                //free( T );
            }
            return NullNode;
        }

        Position
        Find( ElementType X, AATree T, Position NullNode )
        {
            if( T == NullNode )
                return NullNode;
            if( X < T->Element )
                return Find( X, T->Left, NullNode );
            else
            if( X > T->Element )
                return Find( X, T->Right, NullNode );
            else
                return T;
        }

        Position
        FindMin( AATree T, Position NullNode )
        {
            if( T == NullNode )
                return NullNode;
            else
            if( T->Left == NullNode )
                return T;
            else
                return FindMin( T->Left, NullNode );
        }

        Position
        FindMax( AATree T, Position NullNode )
        {
            if( T != NullNode )
                while( T->Right != NullNode )
                    T = T->Right;

            return T;
        }

        /* This function can be called only if K2 has a left child */
        /* Perform a rotate between a node (K2) and its left child */
        /* Update heights, then return new root */

        static Position
        SingleRotateWithLeft( Position K2 )
        {
            Position K1;

            K1 = K2->Left;
            K2->Left = K1->Right;
            K1->Right = K2;

            return K1;  /* New root */
        }

        /* This function can be called only if K1 has a right child */
        /* Perform a rotate between a node (K1) and its right child */
        /* Update heights, then return new root */

        static Position
        SingleRotateWithRight( Position K1 )
        {
            Position K2;

            K2 = K1->Right;
            K1->Right = K2->Left;
            K2->Left = K1;

            return K2;  /* New root */
        }

/* START: fig12_29.txt */
        /* If T's left child is on the same level as T, */
        /* perform a rotation */

        AATree
        Skew( AATree T )
        {
            if( T->Left->Level == T->Level )
                T = SingleRotateWithLeft( T );
            return T;
        }

        /* If T's rightmost grandchild is on the same level, */
        /* rotate right child up */

        AATree
        Split( AATree T )
        {
            if( T->Right->Right->Level == T->Level )
            {
                T = SingleRotateWithRight( T );
                T->Level++;
            }
            return T;
        }
/* END */




/* START: fig12_36.txt */
        AATree
        Insert( ElementType Item, AATree T, Position NullNode )
        {
            if( T == NullNode )
            {
                /* Create and return a one-node tree */
                T = malloc( sizeof( struct AANode ) );
                if( T == NULL )
                    FatalError( "Out of space!!!" );
                else
                {
                    T->Element = Item; T->Level = 1;
                    T->Left = T->Right = NullNode;
                }
            }
            else
            if( Item < T->Element )
                T->Left = Insert( Item, T->Left, NullNode );
            else
            if( Item > T->Element )
                T->Right = Insert( Item, T->Right, NullNode );

            /* Otherwise it's a duplicate; do nothing */

            T = Skew( T );
            T = Split( T );
            return T;
        }
/* END */

/* START: fig12_38.txt */
	AATree
	RemoveHelper( ElementType Item, AATree T, Position NullNode, Position DeletePtr, Position LastPtr)
	{
            if( T != NullNode )
            {
                /* Step 1: Search down tree */
                /*         set LastPtr and DeletePtr */
                LastPtr = T;
                if( Item < T->Element )
                    T->Left = RemoveHelper( Item, T->Left, NullNode, DeletePtr, LastPtr );
                else
                {
                    DeletePtr = T;
                    T->Right = RemoveHelper( Item, T->Right, NullNode, DeletePtr, LastPtr );
                }

                /* Step 2: If at the bottom of the tree and */
                /*         item is present, we remove it */
                if( T == LastPtr )
                {
                    if( DeletePtr != NullNode &&
                             Item == DeletePtr->Element )
                    {
                        DeletePtr->Element = T->Element;
                        DeletePtr = NullNode;
                        T = T->Right;
                        //free( LastPtr );
                    }
                }

                /* Step 3: Otherwise, we are not at the bottom; */
                /*         rebalance */
                else
                    if( T->Left->Level < T->Level - 1 ||
                        T->Right->Level < T->Level - 1 )
                    {
                        if( T->Right->Level > --T->Level )
                            T->Right->Level = T->Level;
                        T = Skew( T );
                        T->Right = Skew( T->Right );
                        T->Right->Right = Skew( T->Right->Right );
                        T = Split( T );
                        T->Right = Split( T->Right );
                    }
            }
            return T;
        }

	AATree
        Remove( ElementType Item, AATree T, Position NullNode )
        {
		Position DeletePtr, LastPtr;
		return RemoveHelper(Item, T, NullNode, DeletePtr, LastPtr);
	}


/* END */

        ElementType
        Retrieve( Position P )
        {
            return P->Element;
        }
