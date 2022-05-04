#include <stdio.h>
#include <unistd.h>

int main()
{
	fork();
	puts("Hi");
	return 0;
}

// Output:
// Hi
// Hi
