/*
Kenneth Adair
This program is primarily taken from K&R pg. 72, but also takes code 
from pg. 71 and pg 69 for the getline function which I renamed to 
getaline to avoid naming conflicts.
This program allows you to run it, then you enter numbers and it adds them.  
If you enter a plus or minus sign in front of the number it will add or 
subtract them depending on which sign you put in front.  
 */

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

/* Rudimentary calculator  */
int main()
{
  double sum, atof(char []);
  char line[MAXLINE];
  int getaline(char line[], int max);

  sum = 0;
  while(getaline(line, MAXLINE) > 0)
    printf("\t%g\n", sum += atof(line));
  return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)    /* skip white space  */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-')
    i++;
  for(val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if(s[i] == '.')
    i++;
  for(power = 1.0; isdigit(s[i]); i++){
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
  }
      return sign * val / power;
}

/* getline: get line into s, return length, taken from pg. 69 K&R */
int getaline(char s[], int lim)
{
  int c, i;
  i = 0;
  while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if(c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}
