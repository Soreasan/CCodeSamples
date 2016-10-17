/* 
Kenneth Adair
K&R pg. 87
So I'm not fully sure what this program is supposed to do.
However it appears to use recursion to print a number as a character or something.  Recursion seems cool though even if this program is weird.
 */

#include <stdio.h>

void printd(int n);

int main(){
  int n = 123;
  printf("%d\n", n);
  printd(n);
}

/* printd: print n in decimal */
void printd(int n)
{
  if(n < 0){
    putchar('-');
    n = -n;
  }
  if(n / 10)
    printd(n / 10);
  putchar(n % 10 + '0');
}
