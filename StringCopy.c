/* 
Kenneth Adair
K&R pg. 105-106.  
Various ways to copy a string, mainly using pointers.
*/
#include <stdio.h>

void strcpyArray(char *s, char *t);
void strcpy1(char *s, char *t);
void strcpy2(char *s, char *t);
void strcpy3(char *s, char *t);

int main(){
  char arr[5] = "hello";
  printf("The string is %s.\n", arr);
  char arr2[5];
  strcpy3(&arr2[0], &arr[0]);
  printf("The copied string is %s.\n", arr2);
  return 0;
}

/* strcpy: copy t to s; array subscript version */
void strcpyArray(char *s, char *t)
{
  int i;
  i = 0;
  while((s[i] = t[i]) != '\0')
    i++;
}

/* strcpy: copy t to s; pointer version 1 */
void strcpy1(char *s, char *t)
{
  while((*s = *t) != '\0'){
    s++;
    t++;
  }
}

/*strcpy: copy  to s; pointer version 2 */
void strcpy2(char *s, char *t)
{
  while((*s++ = *t++) != '\0')
    ;
}

/* strcpy: copy t to s; pointer version 3 */
void strcpy3(char *s, char *t){
  while(*s++ = *t++)
    ;
}
