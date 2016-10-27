/*
Kenneth Adair
Based on K&R pg. 101-102
 */
#include <stdio.h>

#define ALLOCSIZE 25 /* Size of available space  */

//Character array with a size of whatever our ALLOCSIZE is
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
//allocp is a pointer to the next free index of the array and starts at 0
static char *allocp = allocbuf; /* next free position */
//Declarations of variables.
char *alloc(int n);
void afree(char *p);
void addWord(char *p);

//main is only used to test our functions in this program.
int main(){
  allocbuf[0] = 'c';
  allocbuf[1] = 'a';
  allocbuf[2] = 't';
  printf("The characters in allocbuf are: %s\n", allocbuf); 
  char *t = alloc(2);
  printf("The character in slot 2 retrieved by *alloc(int n) is: %c\n", *t);
  return 0;
}

/* return pointer to n characters  */
char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {/* it fits */
    allocp += n;
    return allocp - n; /* old p */
  }else /* not enough room  */
    return 0;
}

//All this does is check if our pointer points to somewhere within the array
//If it does point somewhere within the array the allocp pointer/index is updated
//Otherwise this function/method does nothing.
void afree(char *p) /* free storage pointed to by p  */
{
  //Checks if the pointer is within the area that we're storing 
  if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p; //If the pointer is a legitimate pointer we update allocp to point there
}
/*
1. Input an index/pointer
2. Check if that index/pointer is in our array
3a. If it is in our array update the global index/pointer allocp to equal the index/pointer we just check.  
3b. If it isn't in our array do nothing and leave the global index where it is.
 */
