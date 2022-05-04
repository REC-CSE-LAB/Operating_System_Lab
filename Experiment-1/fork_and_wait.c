#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t rv;
	printf("\nThe process id is %d\n",getpid());

	rv = fork();

	if( rv < 0 ) 	// Error
	{
		puts("Error occured while creating the process");
	}

	else if( rv == 0 )	// Child process
	{
	       puts("\nChild Process");

		int a = 10, b = 20;
 		int max = ( a > b ) ? a : b;

		printf("\nMaximum of %d and %d is %d\n",a,b,max);
		printf("The Child process id is %d\n",getpid());
	}

	else	// Parent proess
	{
		pid_t wait();
		puts("\nParent process");

		int c = 20;
		if( c%2 == 0 )
			printf("\nThe number %d is even.\n",c);
		else
			printf("\nThe number %d is odd.\n",c);

		printf("\nThe parent process id is %d\n",getpid());
	}

	return 0;
}

/*
 * Output:
 *
 * The process id is 16294
 *
 * Parent process
 *
 * Child Process
 *
 * Maximum of 10 and 20 is 20
 * The Child process id is 16295
 *
 * The number 20 is even.
 *
 * The parent process id is 16294
 *
 */
