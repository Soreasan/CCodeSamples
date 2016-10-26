/*
Kenneth Adair
K&R pg. 99
This program finds the length of a string given a pointer.
For some reason it's returning 6 for "hello" though which
I'm not entirely sure why it's doing that.  =(
 */

#include <stdio.h>

int stringLength(char *s);

int main(){
  char arr[5] = "hello";
  printf("The character array is \"%s\".\n", arr);
  int len = stringLength(&arr[0]);
  printf("The length of the array is %i characters.\n", len);
  return 0;
}

/* strlen: return length of string s */
int stringLength(char *s)
{
  int n;
  for(n = 0; *s != '\0'; s++)
    n++;
  return n;
}
