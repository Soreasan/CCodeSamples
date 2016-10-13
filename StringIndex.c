/*
Kenneth Adair
This is my attempt to do Exercise 4-1 on pg. 71 of the K&R book.
 */

#include <stdio.h>
//SIZE will be the size of our array.  Previously I tried using the sizeof(char arr[]) function but it wasn't working so I decided to hardcore the array length for this example.
#define SIZE 5

//Declaring the function that we'll use later
int strrindex(char s[],char t);

//the main
int main()
{
  //The character array or string that we're searching for a specific character in
  char s[SIZE] = "12345";
  //The specific character we'll be searching the String for
  char t = '3';
  //Calling our function to see what the index of the number is
  int answer = strrindex(s, t);
  //Displaying the index that we found the specific character in.  Or if we didn't find it it will return -1 instead.
  printf("%d\n", answer);
}

//The function that's being tested.  
int strrindex(char s[], char t)
{
  //Since arrays are ZERO based we subtract 1 from the array size to start at the last index in the array.
  for(int i = SIZE - 1; i > 0; i--)
    {
        printf("The character in slot %d is %c\n", i, s[i]);
	//If we find the character that we're searching for we'll return the index.
        if(s[i] == t)
	{
	    printf("Found the rightmost string index of the character returned!\n");
            return i;
        }
    }
  printf("%c not found.  Returning -1 since there is no index/answer.\n", t);
  return -1;
}
