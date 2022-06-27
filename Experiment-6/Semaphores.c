// Aim:- Write C Program to implementation of Semaphores

/*
	Algorithm :-
	---------
	
	Step-1 : Start
	Step-2 : Get the no. of jobs from the user.
	Step-3 : When job1 is processing, job2 is also starts processing.
	Step-4 : when job1 enter the critical section, next job start processing
	Step-5 : when job1 comes out of the critical section, next job starts processing
	Step-6 : The above 3 steps are performed for various programs
	Step-7 : Stop
*/


#include <stdio.h>

int main()
{
	int i, a = 1, h = 2, n;
	printf("\nEnter the no. of jobs : ");
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		if( a == 1 )
		{
			printf("processing %d...!\n",i+1);
			a++;
		}
		if( h > 1 )
		{
			if( i+2 <= n )
			{
				printf("\nprocessing %d...!\n",i+2);
			}
			printf("\nProcss %d enter critical section",i+1);
			printf("\nProcss %d leaves critical section",i+1);
		}
		h++;
	}
	getchar();
	return 0;
}

/*
  INPUT/OUTPUT :-
  ------------
	Enter the no. of jobs : 2
	processing 1...!
	
	processing 2...!
	
	Procss 1 enter critical section
	Procss 1 leaves critical section
	Procss 2 enter critical section
	Procss 2 leaves critical section
*/
