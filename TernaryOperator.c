/*
Kenneth Adair
This program is based on concepts found on K&R pg. 51.
It determines which number is bigger than the other.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Sample numbers.
    int a = 15;
    int b = 22;
    //Tell the user what the sample numbers are.
    printf("Int a is %d and int b is %d.\n", a, b);
    //Use the method to display which number is bigger.
    printf("%d is bigger.\n", returnBigger(a,b));
    return 0;
}

int returnBigger(int a, int b)
{
    //this is the format of a ternary operator.
    return (a >  b) ? a : b;
}
