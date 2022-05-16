#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int res, n;
	res = open( "REC", O_WRONLY );
	write( res, "RESCSE\n", 7 );
	printf( "The sender process %d sent data\n", getpid() );
	return 0;
}

// Output :
// Hello World
// The sender process 25662 sent data

