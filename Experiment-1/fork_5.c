#include <stdio.h>
#include <unistd.h>

int fork_example ( void )
{
	int x = 1;
	
	if ( fork() == 0 )	// Child Process
	{
		puts("Hello Child");
	}
	else			// Parent Process
	{
		puts("Hello from parent");
	}
}

int main ()
{
	fork_example();
	return 0;
}

// Output:
// Hello from parent
// Hello Child
