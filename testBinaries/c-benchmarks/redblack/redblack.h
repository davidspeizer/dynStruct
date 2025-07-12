        #include <stdlib.h>

        typedef int ElementType;
        #define NegInfinity (-10000)

        #ifndef _RedBlack_H
        #define _RedBlack_H

        struct RedBlackNode;
        typedef struct RedBlackNode *Position;
        typedef struct RedBlackNode *RedBlackTree;

        RedBlackTree MakeEmpty( RedBlackTree T, Position NullNode );
        Position Find( ElementType X, RedBlackTree T, Position NullNode );
        Position FindMin( RedBlackTree T, Position NullNode );
        Position FindMax( RedBlackTree T, Position NullNode );
        RedBlackTree Initialize( Position *NN );
        RedBlackTree Insert( ElementType X, RedBlackTree T, Position NullNode );
        RedBlackTree Remove( ElementType X, RedBlackTree T );
        ElementType Retrieve( Position P );
        void PrintTree( RedBlackTree T, Position NullNode );

        #endif  /* _RedBlack_H */

/* END */
