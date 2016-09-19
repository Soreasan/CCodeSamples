/*
Kenneth adair
This program takes examples from K&R 2.7 Type Conversions 
starting on page 42.
*/

#include <stdio.h>

int atoi(char s[]);
int lower(int c);
int rand(void);
void srand(unsigned int seed);

int main()
{
	printf("IT WORKED!\n");
	char myString[4] = "test";
	printf("Converting the word 'test' to an integer.\n");
	int testInt = atoi(myString);
	printf("test as a number is: %d \n", testInt);
	printf("Well that did nothing.  It turns out the method turns strings of numbers into integers.  But it doesn't do anything with pure letters.\n");
	int testInt2 = atoi("153");
	printf("The string 153 as an integer is: %d \n", testInt2);
	printf("Converting C to c\n");
	printf("%c, %c\n", 'C', lower('c'));
	printf("Next we'll set the seed to 10 and use that to generate a random number.\n");
	srand(10);
	printf("Alright so that's done.  Next we'll display a random-ish number.\n");
	printf("The random number is: %d\n", rand());
	return 0;
}

/* K&R pg.43 */ 
/* atoi: convert s to integer */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

/* K&R pg. 43 */
/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	if(c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

/* K&R pg. 46 */
unsigned long int next = 1;
/*rand: return pseudo-random integer on 0..32767 */
int rand(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int) (next/65536) % 32768;
}

/*srand: set seed for rand() */
void srand(unsigned int seed)
{
	next = seed;
}
