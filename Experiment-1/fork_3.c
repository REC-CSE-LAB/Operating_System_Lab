#include <stdio.h>
#include <unistd.h>

int main()
{
	fork();
	fork();
	fork();
	puts("Hi");
	return 0;
}

// Output:
// Hi
// Hi
// Hi
// Hi
// Hi
// Hi
// Hi
// Hi
