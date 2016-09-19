/*
Kenneth Adair
This code demonstrates an IF-ELSE statement and is based on K&R page 58.
I modified it a lot because the code in the book is an infinite loop.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 15;
    int v[16] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 18, 19, 20, 21};
    int n = 16;
    int result = binsearch(x, v, n);
    result = -1;
    if(result != -1){
        printf("Found the result in the array!");
    }else{
        printf("Did not find the result in the array!");

    }
    //printf("Hello world!\n");
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high)
    {
        //printf("Low is %d, high is %d\n", low, high);
        mid = (low+high) / 2;
        //Error checking to prevent an infinite loop, I'm not 100% sure if it works, but it works for my example.
        if(low == mid || high == mid)
            return -1;

        if(x < v[mid])
            high = mid + 1;
        else if(x > v[mid])
            low = mid + 1;
        else    /*found match */
            return mid;
    }
    return -1;  /* No match */
}
