/*
Kenneth Adair
Based on K&R pg. 69
This program uses functions/methods to search for strings/lines that match the pattern "ould".  
The way you input text into this program is by running it and then typing the text that you
want to input into the program.  As a note I added a bunch of debugging messages while
I was trying to identify what was going wrong but then figured out that I wasn't inputting
text correctlly.  (I thought maybe this program used commandline arguments lol.)  
But anyway I'm leaving them in just because it's fun to see the debugging messages in action.
 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int getaline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for  */

/* find all lines matching pattern */
int main()
{
  char line[MAXLINE];
  int found = 0;

  while(getaline(line, MAXLINE) > 0){
    printf("Going through the WHILE loop\n");
    if(strindex(line, pattern) >= 0){
      printf("%s", line);
      found++;
    }
  }
  return found;
}

/* getaline: get line into s, return length */
int getaline(char s[], int lim)
{
  printf("getaline method called\n");
  int c, i;

  i = 0;
  while(--lim > 0 && (c=getchar()) != EOF && c != '\n'){
    printf("in getaline if we haven't found the end of line or newline keep going.\n");
    s[i++] = c;
  }
  if(c == '\n'){
    printf("Character is a newline I think?\n");
    s[i++] = c;
  }
  s[i] = '\0';
  printf("getaline method ended.\n");
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  printf("strindex method called\n");
  int i, j, k;

  for(i = 0; s[i] != '\0'; i++){
    for(j=i, k=0; t[k] != '0' && s[j] == t[k]; j++, k++)
      ;
    if(k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
