        #include <stdlib.h>

        typedef int ElementType;

        #ifndef _AATree_H
        #define _AATree_H

        struct AANode;
        typedef struct AANode *Position;
        typedef struct AANode *AATree;

        AATree MakeEmpty( AATree T, Position NullNode );
        Position Find( ElementType X, AATree T, Position NullNode );
        Position FindMin( AATree T, Position NullNode );
        Position FindMax( AATree T, Position NullNode );
        AATree Initialize( void );
        AATree Insert( ElementType X, AATree T, Position NullNode );
        AATree Remove( ElementType X, AATree T, Position NullNode );
        ElementType Retrieve( Position P );

        #endif  /* _AATree_H */

/* END */
