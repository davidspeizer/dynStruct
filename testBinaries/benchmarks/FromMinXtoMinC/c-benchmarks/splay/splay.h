        #include <stdlib.h>

        typedef int ElementType;
        #define Infinity 30000
        #define NegInfinity (-30000)

/* START: fig12_5.txt */
        #ifndef _Splay_H
        #define _Splay_H

        struct SplayNode;

	typedef struct SplayNode *SplayTree;
	typedef struct SplayNode *Position;

	struct SplayNode
	{
		ElementType Element;
		struct SplayNode *Left;
		struct SplayNode *Right;
	};

        SplayTree MakeEmpty( SplayTree T, Position NullNode );
        SplayTree Find( ElementType X, SplayTree T, Position NullNode, Position Header  );
        SplayTree FindMin( SplayTree T, Position NullNode, Position Header );
        SplayTree FindMax( SplayTree T, Position NullNode, Position Header );
        SplayTree Initialize( void );
        SplayTree Insert( ElementType X, SplayTree T, Position NullNode, Position Header );
        SplayTree Remove( ElementType X, SplayTree T, Position NullNode, Position Header  );
        ElementType Retrieve( SplayTree T );  /* Gets root item */

        #endif  /* _Splay_H */
/* END */
