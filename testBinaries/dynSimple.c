#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void print(char *str)
{
  puts(str);
  str[1] = 'a';
  puts(str);
}

int main()
{
  char *str;

  str = malloc(5);
  strcpy(str, "test");
  str[4] = 0;
  print(str);

  free(str);
}
