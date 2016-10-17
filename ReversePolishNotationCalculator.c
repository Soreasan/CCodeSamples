/*
Kenneth Adair
From K&R pg. 74 it states that:
"In reverse Polish notation, each operator follows its operands; an infix expression like
(1 - 2) * (4 + 5)
is entered as
1 2 - 4 5 + *
Parentheses are not needed; the notation is unambiguous as long as we know how many operands each operator expects"
This program is taken from section 4.3 on pg 73 of the K&R book called "External Variables"
This program does math using a STACK.  
The code is taken from pages 76-79.
 */

//pg. 76 K&R
#include <stdio.h>
#include <stdlib.h>    /* for atof() */

#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish Calculator */
int main()
{
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF)
    {
      switch(type){
      case NUMBER:
	push(atof(s));
	break;
      case '+':
	push(pop() + pop());
	break;
      case '*':
	push(pop() * pop());
	break;
      case '-':
	op2 = pop();
	push(pop() - op2);
	break;
      case '/':
	op2 = pop();
	if(op2 != 0.0)
	  push(pop() / op2);
	else
	  printf("error: zero divisor\n");
	break;
      case '\n':
	printf("\t%.8g\n", pop());
	break;
      default:
	printf("error: unknown command %s\n", s);
	break;
      }
    }
  return 0;
}

//pg. 77 K&R
#define MAXVAL 100    /* maximum depth of val stack */

int sp = 0;    /* next free stack position */
double val[MAXVAL];    /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else{
    printf("error: stack empty\n");
    return 0.0;
  }
}

//pg. 78
#include <ctype.h>
int getch(void);
void ungetch();

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if(!isdigit(c) && c != '.')
    return c;    /* not a number */
  i = 0;
  if(isdigit(c))    /* collect integer part */
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}

//pg. 79
#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;    /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if(bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
