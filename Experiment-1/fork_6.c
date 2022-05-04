#include <stdio.h>
#include <unistd.h>

int fork_example ( void )
{
	int x = 1;
	
	if ( fork() == 0 )	// Child Process
	{
		printf("x = %d\n",++x);
	}
	else			// Parent Process
	{
		printf("x = %d\n",--x);
	}
}

int main ()
{
	fork_example();
	return 0;
}

// Output:
// x = 0
// x = 2

