/*
Kenneth Adair
K&R pg. 87-88
This is a quicksort algorithm using recursion from the K&R book.
"Another good example of recursion is quicksort, a sorting algorithm
developed by C. A. R. Hoare in 1962.  Given an array, one element
is chosen and the others are partitioned into two subsets - those
less than the partition element and those greater than or equal to it.
The same process is then applied recursively to two subsets.  When a 
subset has fewer than two elements, it doesn't need any sorting;
this stops the recursion."
 */

#include <stdio.h>

void qsort(int v[], int left, int right); 

int main(){
  int v[10] = {5, 4, 3, 1, 8, 9, 0, 2, 6, 7};
  for(int i = 0; i < 10; i++)
    printf("%d ", v[i]);
  printf("\nAfter Sorting:\n");
  qsort(v,0,9);
  for(int i = 0; i < 10; i++)
    printf("%d ", v[i]);
  printf("\n");
  return 0;
}
/*qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);

  if(left >= right)    /* do nothing if array contains */
    return;    /* fewer than two elements */
  swap(v, left, (left + right)/2);  /*move partition elem */
  last = left;    /* to v[0] */
  for(i = left+1; i <= right; i++) /* partition */
    if(v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);    /* restore partition elem */
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
