/*
Kenneth Adair
K&R pg. 64
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int test;
    test = -5;
    char s[5] = {"hello"};
    printf("%s\n", s);
    itoa(test, s);
    printf("%s\n", s);
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if((sign = n) < 0)  /* record sign */
        n = -n;
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';  /* get next digit */
    }while((n /= 10) > 0);      /* delete it */
    if(sign < 0)
        s[i++] = '\0';
        reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for(i = 0, j = strlen(s)-1;i<j;i++,j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
