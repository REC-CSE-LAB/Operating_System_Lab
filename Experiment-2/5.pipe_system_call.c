#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd[2],n;
	char buffer[100];
	
	pid_t p;
	
	pipe(fd);
	p=fork();

	if( p > 0 )
	{
		printf("\nParent Pass some data to child\n");
		write( fd[1], "Hello\n", 6);
		pid_t wait();
	}

	else if ( p == 0 )
	{
		printf("\nChild Process reads some information from parent\n");
		read( fd[0], buffer, 100 );
		write( 1, "Hai\n", 5);
	}

	return 0;
}

// Output :
// Parent Pass some data to child
//
// Child Process reads some information from parent
// Hai
