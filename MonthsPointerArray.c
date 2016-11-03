/*
Kenneth Adair
K&R pg. 113
*/
#include <stdio.h>

char *month_name(int n);

int main()
{	int n = 5;
	char *month = month_name(n);
	printf("The %i-th month of the year is %c\n", n, *month);
}

/* month_name: return name of the n-th month */
char *month_name(int n)
{
	static char *name[] = {
		"illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}
