/*
Kenneth Adair
K&R pg. 96
This program swaps two integer values using pointers.
 */

#include <stdio.h>

void swap(int *px, int *py);

int main(){
  int a, b;
  a = 5;
  b = 7;
  printf("Before the swap function:\n a = %d\n b = %d\n", a, b);
  swap(&a, &b);
  printf("After the swap function:\n a = %d\n b = %d\n", a, b);
}

/* Interchange *px and *py  */
void swap(int *px, int *py)
{
  int temp;
  temp = *px;
  *px = *py;
  *py = temp;
}
