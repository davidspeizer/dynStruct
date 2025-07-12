//#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   prints( Str ), prints("\n"), mincexit( 1 )

int mincexit(int);
