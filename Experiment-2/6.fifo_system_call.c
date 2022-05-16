#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int res;
	res = mkfifo( "REC", 0777);
	printf("Named pipe created\n");
	return 0;
}

// Output :
// Named pipe created

