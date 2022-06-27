// Aim:- To implement bankers algorithm for deadlock detection

// Source code:
#include <stdio.h>

int main()
{
	int request[10][10], allocation[10][10], available[10];
	int np, nr, i, j, count = 0, flag[10], p = 0;
	
	puts("\tDEADLOCK DECTECTION");
	
	printf("Enter no. of processes : ");
	scanf("%d",&np);
	
	printf("Enter no. resources : ");
	scanf("%d",&nr);
	
	puts("Enter the request matrix :-");
	for( i = 0; i < np; ++i )
	{
		for( j = 0; j < nr; ++j )
			scanf("%d",&request[i][j]);
		flag[i] = 0;
	}
	fflush(stdin);
	
	puts("Enter the allocation matrix : ");
	for( i = 0; i < np; ++i )
		for( j = 0; j < nr; ++j )
			scanf("%d",&allocation[i][j]);
	fflush(stdin);
			
	puts("Enter the available matrix : ");
	for( j = 0; j < nr; j++ )
		scanf("%d",&available[j]);
		
	for( i = 0; i < np; i++ )
	{
		count = 0;
		for( j = 0; j < nr; j++ )
			if( allocation[i][j] == 0 )
				count++;
		if( count == nr )
			flag[i] = 1;
	}
	
	while( p <= np )
	{
		for( i = 0; i < np; i++ )
		{
			if( flag[i] == 0 )
			{
				count = 0;
				for( j = 0; j < nr; j++ )
					if( available[j] >= request[i][j] )
						count++;
				if( count == nr )
				{
					for( j = 0; j < nr; j++ )
						available[j] += allocation[i][j];
					flag[i] = 1;
				}
			}
		}
		p++;
	}
	
	for( i = 0; i < np; ++i )
	{
		if( flag[i] == 0 )
			printf("p[%d] leads to deadlock state\n",i);
		else
			printf("p[%d] does not create deadlock\n",i);
	}
	
	getchar();
	return 0;
}

/*
	INPUT/OUTPUT :-
	------------
	
			DEADLOCK DECTECTION
		Enter no. of processes : 4
		Enter no. resources : 4
		Enter the request matrix :-
		0 1 0 0 1
		0 0 1 0 1
		0 0 0 0 1
		1 0 1 0 1
		Enter the allocation matrix :
		1 0 1 1 0
		1 1 0 0 0
		0 0 0 1 0
		0 0 0 0 0
		Enter the available matrix :
		0 0 0 0 1
		p[0] leads to deadlock state
		p[1] leads to deadlock state
		p[2] does not create deadlock
		p[3] does not create deadlock
*/
