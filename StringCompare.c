/*
Kenneth Adair
pg. 106 K&R

strcmp(s,t) compares the character strings s and t and returns negative, zero, or 
positive if s is lexicographically less than, equal to, or greater than t.

From Wikipedia:
Lexigographical order - "a generalization of the way the alphabetical order of words is based on the alphabetical order of their component letters."

From Quora:
Hong-Yi Dai
"Lexicographical order is alphabetical order
preceded by a length comparison.  That is to
say, a string a is lexicogrpahically smaller than
a string b:
-IF the length of a is smaller than the length of b, OR
-ELSE they are the same length AND a is alphabetically smaller than b."
 */

#include <stdio.h>

int strcmpLoop(char *s, char *t);
int strcmpPointer(char *s, char *t);

int main(){
  char arr1[5] = "hello";
  char arr2[8] = "apikachu";
  printf("arr1 is %s and arr2 is %s.\nIf lexicographical order picks the shortest then the function will return a positive number.\nIf lexicographical order picks strictly alphabetical order then it will return a negative number.\n", arr1, arr2);
  printf("%i\n", strcmpPointer(&arr1[0], &arr2[0]));
  return 0;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t  */
int strcmpLoop(char *s, char *t){
  int i;

  for(i = 0; s[i] == t[i]; i++)
    if(s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t  */
int strcmpPointer(char *s, char *t){
  for(; *s == *t; s++, t++)
    if(*s == '\0')
      return 0;
  return *s - *t;
}
