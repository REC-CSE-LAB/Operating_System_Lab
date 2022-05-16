#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int res, n;
	char buffer[100];
	
	res = open("REC", O_RDONLY );
	n = read( res, buffer, 100 );

	printf("Reader process %d started\n", getpid() );
	printf("Data received by receiver %d is : %s\n", getpid(), buffer );
	return 0;
}

// Output :
// Reader process 25744 started
// Data received by receiver 25744 is : RESCSE

