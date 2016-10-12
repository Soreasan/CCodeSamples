/*
Kenneth Adair
K&R pg. 71
This program is based off the code in the book on page 71.  Although I had
to add a bunch extra to actually use the function.  
 */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(){
  char s[5] = "54321";
  printf("This is a string/character array; %s\n", s);
  printf("This is a double after being converted by our method: %f\n", atof(s));

  return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
  double val, power;
  int i, sign;
  for(i = 0; isspace(s[i]); i++) /*skip white space */
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
