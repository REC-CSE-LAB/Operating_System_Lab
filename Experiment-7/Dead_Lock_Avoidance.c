// Aim:- To implement the program for the deadlock avoidance

#include <stdio.h>

int main()
{
	int alloc[10][10], max[10][10], need[10][10], avail[10];
	int work[10], finish[10] = {0}, i, n, j, r, c = 0, p = 0;
	int ss[0], f;
	
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	
	printf("Enter the number of resources : ");
	scanf("%d",&r);
	
	puts("Enter the allocation matrix :-");
	for( i = 0; i < n; ++i )
		for( j = 0; j < r; ++j )
			scanf("%d",&alloc[i][j]);
			
	puts("Enter the max matrix :-");
	for( i = 0; i < n; i++ )
		for( j = 0; j < r; j++ )
			scanf("%d",&max[i][j]);
			
	puts("Enter the available matrix :-");
	for( j = 0; j < r; j++ ) 
		scanf("%d", &avail[j]);
	
	for( i = 0; i < n; i++ )
		for( j = 0; j < r; j++ )
			need[i][j] = max[i][j];
			
	while(1)
	{
		for( f = 0, i = 0; i < n; i++ )
		{
			if( finish[i] == 0 )
				continue;
			else
				break;
		}
		if( j == r )
		{
			for( j = 0; j < r; j++ )
				avail[i] += alloc[i][j];
			f = 1;
			finish[i] = 1;
			ss[p++] = i+1;
			c++;
		}
		if( f == 0)
			break;
		if( f == 0 || c == n )
			break;
		else
		{
			printf("safe sequence is: " );
			for( i = 0; i < n; i++ )
				printf("%d ",ss[i]);
		}
	}
	getchar();
	return 0;
}

/*
	INPUT/OUTPUT :-
	------------
	
		Enter the number of processes : 5
		Enter the number of resources : 3
		Enter the allocation matrix :-
		0 1 0
		2 0 0
		3 0 2
		2 1 1
		0 0 2
		Enter the max matrix :-
		7 5 3
		3 2 2
		9 0 2
		2 2 2
		4 3 3
		Enter the available matrix :-
		3 3 2
		safe sequence is: 2 4 5 1 3
*/
