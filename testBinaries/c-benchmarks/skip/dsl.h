        #include <stdlib.h>

        typedef int ElementType;
        #define Infinity (10000)

        #ifndef _SkipList_H
        #define _SkipList_H

        struct SkipNode;
        typedef struct SkipNode *Position;
        typedef struct SkipNode *SkipList;

        SkipList MakeEmpty( SkipList L, Position Bottom, Position Tail );
        Position Find( ElementType X, SkipList L, Position Bottom );
        Position FindMin( SkipList L, Position Bottom  );
        Position FindMax( SkipList L, Position Bottom, Position Tail  );
        SkipList Initialize(  Position *Bottom, Position *Tail );
        SkipList Insert( ElementType X, SkipList L, Position Bottom, Position Tail );
        SkipList Remove( ElementType X, SkipList L );
        ElementType Retrieve( Position P );

        #endif  /* _SkipList_H */

/* END */
