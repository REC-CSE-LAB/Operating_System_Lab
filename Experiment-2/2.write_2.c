#include <stdio.h>
#include <unistd.h>

int main()
{
	int count;
	count = write(1,"hello\n",6);
	printf("The return value is : %d\n",count);
	return 0;
}

// Output:
// hello
// The return value is : 6

