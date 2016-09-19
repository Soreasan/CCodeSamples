/*
Kenneth Adair
K&R 29
This program gets as much user input as the user wants to before
inputting ctrl+d (EOF) and then repeats back the longest line
that the user typed out.  
As a side note I had to alter my program and change getline to
getlinez because getline is in the standard library now.  
*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

/* Changed getline to getlinez because getline conflicts with the standard library  */
int getlinez(char s[], int lim);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;		/* current line length */
	int max;		/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while((len = getlinez(line, MAXLINE)) > 0)
		if(len > max){
			max = len;
			copy(longest, line);
		}
	if(max > 0)	/* there was a line */
		printf("%s", longest);
	return 0;
}

/* getlinez: read a line into s, return length */
int getlinez(char s[], int lim)
{
	int c, i;
	
	for(i = 0; i < lim - 1 && (c=getchar()) != EOF && c !='\n'; ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
