/*
Kenneth Adair
This code is based on the example on page 66 of the K&R book.
*/

#include <stdio.h>

int main(){
  int match = -1;
  int a[5] = {6, 7, 8, 9, 10};
  int b[7] = {1, 2, 3, 4, 5, 6, 7};
  
  for(int i = 0; i < sizeof(a); i++){
    for(int j = 0; j < sizeof(b); j++){
      if(a[i] == b[j]){
	match = a[i];
	goto found;
      }
    }
  }
  /* didn't find any common element  */
  printf("\nThe arrays don't have any matching elements.\n");
  return 0;
  
 found:
  /* got one: a[i] == b[j] */
  printf("The common element in these arrays is %d\n", match);
  return 0;
}
