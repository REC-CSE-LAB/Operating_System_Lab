#include <stdio.h>
#include <unistd.h>

int main()
{
	char buff[30];
	printf("\nEnter data : ");
	read( 0, buff, 20 );
	write( 1, buff, 10 );
	return 0;
}

// Input :
// hello world

// Output : 
// Enter data : hello world
// hello world
