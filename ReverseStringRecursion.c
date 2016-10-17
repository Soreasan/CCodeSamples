/*
kenneth Adair
This was my attempt at Exercise 4-13 on page 88 of K&R.
"Exercise 4-13.  Write a recursive version of the function reverse(s),
which reverses the string s in place."
I ended up doing two attempts on my own which kinda sorta work.  
A few things that threw me off is that there wasn't an easy way
to get an array's length in C that I could easily find.  In addition
another thing that threw me off is that once you pass an array into
a method in C it passes a pointer instead of the entire array which
made it harder to work with.  Another issue I bumped into is that
you can't pass a substring or part of the array in C, at least for this
problem since it wants you to change the thing in place.
So this specific challenge ended up taking me way longer than I 
anticipated and made me miss Java where you can easily access
an array's length.  
 */

#include <stdio.h>
#include <string.h>

void reverseWithLoops(char s[], int size);
void reverseString(char s[], int size, int left, int right); 
void reverse(char s[]);

int main(){
  printf("Testing reversing a string using loops:\n");
  char s[5]  = "hello";
  printf("%s\n", s);
  reverseWithLoops(s, 5);
  printf("%s\n", s);

  printf("Testing reversing a string using recursion:\n");
  char mine[5] = "hello";
  printf("%s\n", mine);
  reverseString(mine, 5, 0, 4);
  printf("%s\n", mine);

  printf("Testing reversing a string using code I found on the internet:\n");
  char yours[5] = "hello";
  printf("%s\n", yours);
  reverse(yours);
  printf("%s\n", yours);
  return 0;
}

/********************************************************
This one reverses the string using recursion.
Unfortunately we need a ton of extra variables because
when we pass an array into a method it passes the pointer
when we're programming in C instead of the whole array.  
This means we don't have the size of the array.  
In addition because we don't have a substring method and 
the challenge wants us to reverse the string in place
which means we can't create new arrays and pass them into
the function recursively.  
*********************************************************/
void reverseString(char s[], int size, int left, int right){
  char temp;
  if(left >= right)
    return;
  temp = s[right];
  s[right] = s[left];
  s[left] = temp;
  reverseString(s, size, ++left, --right);
}

//This one reverses the string with just loops
void reverseWithLoops(char s[], int size)
{
  //temp is used to store a value while we shuffle them around
  char temp;
  for(int i = 0; i < size - 1; i++){
    //If we've gone through half the array or more we stop reversing the array since if we keep going we'll reverse the reversed array and make it normal again.
    if(i >= size - i - 1)
      return;
    //These three statements trade two characters in the string
    temp = s[size - i - 1];
    s[size - i - 1] = s[i];
    s[i] = temp;
  }
}

/********************************************************************
The above 2 solutions are the solutions I created myself.
The one below came from a website.
http://www.learntosolveit.com/cprogramming/Ex_4.13_reverse_string.html
**********************************************************************/
void reverse(char s[])
{
    void reverser(char s[],int i,int len);

    reverser(s,0,strlen(s));
}

/* reverser: reverse string s in place; recursive */

void reverser(char s[],int i,int len)
{
    int c,j;

    j = len - (i + 1);
    
    if( i < j )
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;

        reverser(s,++i,len);
    }
}
