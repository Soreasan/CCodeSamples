/*
Kenneth Adair
K&R pg. 62
Reverses a string in place.
*/

#include <stdio.h>

int main()
{
    char hello[] = "Hello world!\n";
    printf("%s", hello);
    voidreverse(hello);
    printf("%s", hello);
    return 0;
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
