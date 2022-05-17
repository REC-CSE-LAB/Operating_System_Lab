#include <stdio.h>
#include <stdlib.h>

int main()
{
	int bt[10] = {0}, at[10] = {0}, tat[10] = {0}, wt[10] = {0}, ct[10] = {0};
	int n, sum = 0;
	int totaltat = 0, totalwt = 0;
	system("clear");
	printf("Enter the number of the process : ");
	scanf("%d",&n);
	printf("Enter the arrival time and bust time :\n\n");
	for( int i = 0; i < n; ++i)
	{
		printf("Enter the arrival time %d : ", i+1 );
		scanf("%d",&at[i]);
		printf("Enter the bust time %d : ", i+1 );
		scanf("%d",&bt[i]);
		printf("\n");
	}
	for( int j = 0; j < n; ++j )
	{
		sum += bt[j];
		ct[j] += sum;
	}
	for( int i = 0; i < n; ++i )
	{
		tat[i] = ct[i]-at[i];
		totaltat += tat[i];
	} 
	for( int k = 0; k < n; ++k )
	{
		wt[k] = tat[k]-bt[k];
		totalwt = wt[k];
	}
	printf("solutions :\n");
	printf("P\tAT\tBT\tCT\tTAT\tWT\t \n\n");
	for( int i = 0; i < n; ++i )
	{ 
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("Average TAT time : %.2f\n", totaltat/(float)n);
	printf("Average waiting time : %.2f\n",totalwt/(float)n); 
	return 0;
}
