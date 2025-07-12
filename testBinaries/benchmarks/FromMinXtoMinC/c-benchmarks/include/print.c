#include <stdio.h>
#include "print.h"

int
prints(char *string)
{
	printf("%s", string);
        return 0;
}

int
print8(signed char i8)
{
	printf("%d", i8);
        return 0;
}

int
print16(signed short i16)
{
	printf("%d", i16);
        return 0;
}

int
print32(signed int i32)
{
	printf("%d", i32);
        return 0;
}
