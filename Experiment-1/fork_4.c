#include <stdio.h>
#include <unistd.h>

int main()
{
	int p;
	p = fork();
	if( p > 0 )
	{
		fork();
		puts("Hi");
	}
	puts("Hello");
	return 0;
}

// Output:
// Hi
// Hello
// Hi
// Hello
// Hello
