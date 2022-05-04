#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("\nThe process id of \"hello.c\" is %d",getpid());
	puts("\nCSE-B");
	return 0;
}

/*
 * Output:
 *
 * The process id of "hello.c" is 19606
 * CSE-B
 *
 */
