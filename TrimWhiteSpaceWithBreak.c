/*
Kenneth Adair
K&R pg. 65
This program is based on the trim function on page 65.
However, I added the printf statements so the user
would know when we're removing whitespace from the end.
Without those printf messages since the whitespace is removed
from the back there's no way for the user to know the function
has done anything.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trim(char s[]);

int main()
{   char myString[] = "Hello world!\n\t    ";
    printf("\nThe phrase above has a newline, a tab, and 4 spaces.  This means it should say \"Removed whitespace from the end.\" about 6 times.\n");
    printf("\n%s\n", myString);
    int whatIsThis = trim(myString);
    printf("\n%s\n", myString);
    return 0;
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
    int n;

    for(n = strlen(s)-1; n >= 0; n--)
        if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
        else
            printf("Removed whitespace from the end.\n");
    s[n + 1] = '\0';
    return n;
}
