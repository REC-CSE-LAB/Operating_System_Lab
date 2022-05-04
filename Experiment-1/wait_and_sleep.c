#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t rv;
	printf("\nThe Process id is %d\n",getpid());
	
	rv = fork();

	if( rv < 0 )
	{
		puts("Error occured while creating the process");
	}
	
	else if ( rv == 0 )	// Child Process
	{
		printf("The Chile process id is : %d\n",getpid());
	}

	else 	// Parent Process
	{
		pid_t wait();

		puts("Parent Proces");
		printf("The parent process is has %d\n",getpid());
		sleep(20);
	}
	return 0;
}

// Output:
// The Process id is 11755
// Parent Proces
// The Chile process id is : 11756
// The parent process is has 11755
