/*
Kenneth Adair
K&R pg. 97
This program grabs the commandline input from the user and if it's a number moves it into a variable using the pointer.
 */

#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int);
void getint(int *pn);
char buf[BUFSIZE]; /* buffer for ungetch  */
int bufp = 0; /* next free position in buf  */
int getch(void);
void ungetch(int c);

int main(){
  int foo;
  getint(&foo);
  printf("After using getint(&foo) we get the user's input which is %d.\n", foo);
  return 0;
}

/* getint: get next integer from input into *pn */
void getint(int *pn)
{
  int c, sign;

  /* skip white space  */
  while(isspace(c = getch()))
    ;
  if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
    ungetch(c); /* it's not a number */
    return;
  }
  sign = (c == '-') ? -1 : 1;
  if(c == '+' || c == '-')
    c = getch();
  for(*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if(c != EOF)
    ungetch(c);
  return;
}

//taken from pg 79 of K&R
int getch(void) /*get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input  */
{
  if(bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
