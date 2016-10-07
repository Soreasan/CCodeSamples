/*
Kenneth Adair
K&R page 65
The trim function is supposed to remove trailing blanks, tabs, and newlines.  i attemped to create my own test method but I can't tell if it's working.  Nevertheless I must move on to the next section.  =(
 */

#include <stdio.h>
#include <string.h>

int trim(char s[]);
int test();

int main()
{
  int myTest = test();
  return 0;
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
  int n;
  for(n = strlen(s)-1; n>= 0; n--)
	if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
	  break;
  /*s[n+1] = '\0';*/
      return n;
}

int test(){
  char s[10] = " a a a   ";
  printf("%s\n", s);
  s = trim(s);
  printf("%s\n", s);
  return 0;
}
