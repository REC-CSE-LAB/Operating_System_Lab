#include <stdio.h>
#include <unistd.h>

int main()
{
	char buffer[50];
	printf("Enter data : ");
	read(0,buffer,10);
	return 0;
}

// Input : 
// hello

// Output :
// Enter data : hello
