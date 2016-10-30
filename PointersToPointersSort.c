/*
Kenneth Adair
K&R pg. 108-109
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /*max lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */
#define BUFSIZE 10000
static char allocbuf[BUFSIZE];
static char *allocp = allocbuf;

char *lineptr[MAXLINES]; /* pointers to text lines  */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int getaline(char *, int);
char *alloc(int);

/* sort input lines */
int main()
{
  int nlines; /* number of input lines read */

  if((nlines = readlines(lineptr, MAXLINES)) >= 0){
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  }else{
    printf("error: inpute too big to sort\n");
    return 1;
  }
}

/*readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getaline(line, MAXLEN)) > 0)
    if(nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else{
      line[len-1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
  int i;

  for(i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

/* getline: read a line into s, return length */
int getaline(char s[], int lim)
{
  int c, i;

  for(i=0; i<lim - 1 && (c=getchar())!=EOF && c!= '\n'; ++i)
    s[i] = c;
  if(c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

char *alloc(int n)
{
  if(allocbuf + BUFSIZE - allocp >= n)
    {
      allocp += n;
      return allocp - n;
    }
  else{
    return NULL;
  }
}
