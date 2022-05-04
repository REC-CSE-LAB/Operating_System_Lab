#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("\nI am in \"execv_sys_call.c\"\n");
	printf("\nThe process id of \"execv_sys_call.c\" is %d\n",getpid());

	char *args[] = { "./hello", NULL };
	execv( args[0], args );

	puts("\nThis message will not be printed");
	return 0;
}

/*
 * Output:
 *
 * I am in "execv_sys_call.c"
 *
 * The process id of "execv_sys_call.c" is 19606
 *
 * The process id of "hello.c" is 19606
 * CSE-B
 *
 */
