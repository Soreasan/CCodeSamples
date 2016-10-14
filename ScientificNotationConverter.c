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

double powerFunction(double base, double exp);

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

  //Skips all white space in the front I think
  for (i = 0; isspace(s[i]); i++)
    ;
  //If the first non-whitespace is a minus sign change it to negative
  sign = (s[i] == '-') ? -1 : 1;
  //Appears to skip additional pluses and minuses
  if(s[i] == '+' || s[i] == '-')
    i++;
  //goes through and multiplies the current number by 10 b/c you found a new digit and adds the new number.
  for(val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  //If you find a decimal skip it and go to the next logic.
  if(s[i] == '.')
    i++;
  //Multiply the value by 10 to move it a digit and add the new digit to the end
  //Also multiply power by 10 so you know how much to divide the number by
  for(power = 1.0; isdigit(s[i]); i++){
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
  }

  /*****************************************************************************
    NEW CODE TO EXTEND ATOF TO HANDLE SCIENTIFIC NOTATION OF THE FORM 123.45e-6
  ******************************************************************************/
  //Check for an e or E
  if(s[i] == 'e' || s[i] == 'E')
  {
    //This will be used to make the number either larger or smaller
    double decimalMover = 10.0;
    printf("Found an e or E in your format!\nMoving to the next space to check for a + or - sign.\n");
    i++;
    //Check for a + or - sign because that will determine if our exponent makes our number smaller or bigger
    if(s[i] == '-')
    {
      printf("Found a - sign.\n");
      decimalMover = 0.1;
      i++;
    }else if(s[i] == '+')
    {
      printf("Found a + sign.\n");
      i++;
    }
    //Next get the number after the e and + or - sign to see how big or small our number will get
    double expVal;
    for(expVal = 0.0; isdigit(s[i]); i++)
        expVal = 10.0 * expVal + (s[i] - '0');
    //At this point expVal will have the number after the e.
    //Our next step will be calculate the number that we're going to multiple the val by
    printf("The number of the e and + or - sign is: %lf\n", expVal);
    double numberToMultiplyPowerBy = powerFunction(decimalMover, expVal);
    printf("The number that we will multiply the power by is %lf\n", numberToMultiplyPowerBy);
    //Next we multiply power by numberToMultiplyPowerBy and then make that the new power, then we should be done
    power = power * numberToMultiplyPowerBy;
    printf("return sign * val / power is %d * %lf / %lf\n", sign, val, power);
  }
  /*****************************************************************************
    NEW CODE TO EXTEND ATOF TO HANDLE SCIENTIFIC NOTATION OF THE FORM 123.45e-6
  ******************************************************************************/
  
  return sign * val * power;
}

/* getaline: get line into s, return length, taken from pg. 69 K&R */
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

double powerFunction(double base, double exp)
{
    double result = 1.0;
    int MAX = (int) exp;
    for (int i = 0; i < MAX; i++)
        result *= base;
    printf("%lf raised to the %lf power is %lf.\n", base, exp, result);
    return result;
}
