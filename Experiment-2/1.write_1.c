#include <stdio.h>
#include <unistd.h>

int main()
{
	write(1,"hello\n",6);
	return 0;
}

// Output :
// hello
