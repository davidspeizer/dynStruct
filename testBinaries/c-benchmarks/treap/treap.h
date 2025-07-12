        #include <stdlib.h>

        typedef int ElementType;
        #define Infinity RAND_MAX 

        #ifndef _Treap_H
        #define _Treap_H

        struct TreapNode;
        typedef struct TreapNode *Position;
        typedef struct TreapNode *Treap;

        Treap MakeEmpty( Treap T, Position NullNode );
        Position Find( ElementType X, Treap T, Position NullNode );
        Position FindMin( Treap T, Position NullNode );
        Position FindMax( Treap T, Position NullNode );
        Treap Initialize( void );
        Treap Insert( ElementType X, Treap T, Position NullNode );
        Treap Remove( ElementType X, Treap T, Position NullNode );
        ElementType Retrieve( Position P );



        #endif  /* _Treap_H */

/* END */
