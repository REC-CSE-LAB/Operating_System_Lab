#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, p[10], min, k = 1, btime = 0; 
	int bt[10], temp, j, at[10], wt[10], tt[10], ta = 0, sum = 0;
	float wavg = 0, tavg = 0, tsum = 0, wsum = 0;

	printf("Short Job First Scheduling Algorithm\n");
	printf("Enter no. of process : ");
	scanf("%d",&n);

	for( i = 0; i < n; ++i )
	{
	    p[i]=i+1;
		printf("\n\nEnter arrival time of %d process: ",i+1);
		scanf("%d",&at[i]);
		printf("Enter the burst time of %d process: ", i+1 );
		scanf("%d",&bt[i]);
	}

	for( i = 0; i < n; ++i )
	{
		for( j = 0; j < n; ++j )
		{
			if( at[i] < at[j] )
			{
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
				temp = at[j];
				at[j] = temp;
				temp = bt[j];
				bt[j] = bt[i];
				bt[i] = temp;
			}
		}
	}

	for( j = 0; j < n; ++j )
	{
		btime = btime+bt[j];
		min = bt[k];
		for( i = k; i < n; ++i )
		{
			if( btime >= at[i] && bt[i] < min )
			{
				temp = p[k];
				p[k] = p[i];
				p[i] = temp;
				temp = at[k];
				at[k] = at[i];
				at[i] = temp;
				temp = bt[k];
				bt[k] = bt[i];
				bt[i] = temp;
			}
		}
		++k;
	}
	
	wt[0] = 0;
	for( i = 1; i < n; ++i )
	{
		sum = sum + bt[i-1];
		wt[i] = sum-at[i];
		wsum += wt[i];
	}
	wavg = wsum/n;
	
	for( i = 0; i < n; ++i )
	{
		ta = ta + bt[i];
		tt[i] = ta - at[i];
		tsum +=  tt[i];
	} 
	tavg = tsum/n;

	printf("\nProcess\tBT\tAT\tWT\tTAT\n");
	for(i=0;i<n;++i)
		printf("\nP%d\t%d\t%d\t%d\t%d\n",p[i],bt[i],at[i],wt[i],tt[i]);
	printf("\nAverage waiting time : %.2f",wavg);
	printf("\nAverage turn around time : %.2f",tavg);
	return 0;
}

/*

INPUT/OUTPUT :
-------------

Short Job First Scheduling Algorithm
Enter no. of process : 4


Enter arrival time of 1 process: 0
Enter the burst time of 1 process: 3


Enter arrival time of 2 process: 0
Enter the burst time of 2 process: 6


Enter arrival time of 3 process: 0 
Enter the burst time of 3 process: 7


Enter arrival time of 4 process: 0
Enter the burst time of 4 process: 8

Process BT      AT     WT      TAT

P1      3       0       0       3

P2      6       0       3       9

P3      7       0       9       16

P4      8       0       16      24

Average waiting time : 7.00
Average turn around time : 13.00

*/
