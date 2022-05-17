#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, p[10]={1,2,3,4,5,6,7,8,9,10}, min, k = 1, Dtime = 0; 
	int bt[10], temp, j, at[10], wt[10], tt[10], ta = 0, sum = 0;
	float wavg = 0, tavg = 0, tsum = 0, wsum = 0;

	printf("Short Job First Scheduling Algorithm\n");
	printf("Enter no. of process : ");
	scanf("%d",&n);

	for( i = 0; i < n; ++i )
	{
		printf("Enter arrival time of %d process",i+1);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time of %d process", i+1 );
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
				at[k] = ak[i];
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
		wsum = wt[i];
	}
	wavg = wsum/n;
	
	for( i = 0; i < n; ++i )
	{
		ta = ta + bt[i];
		bt[i] = ta - at[i];
		bsum = tsum + tt[i];
		bavg = tsum/n;
	} 

	printf("\nProcess\tBT\tTAT\tWT\tTAT\n");
	for(
		printf("\nP%d\t%d\t%d\t%d\t%d",p[i],bt[i],at[i],ut[i],tt[i]);
	return 0;
}

