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

// OUTPUT:
// Enter the number of the process : 6
// Enter the arrival time and bust time :
//
// Enter the arrival time 1 : 0
// Enter the bust time 1 : 3
//
// Enter the arrival time 2 : 1
// Enter the bust time 2 : 2
//
// Enter the arrival time 3 : 2
// Enter the bust time 3 : 1
//
// Enter the arrival time 4 : 3
// Enter the bust time 4 : 4
//
// Enter the arrival time 5 : 4
// Enter the bust time 5 : 5
//
// Enter the arrival time 6 : 5
// Enter the bust time 6 : 2
//
// solutions :
//	P	AT	BT	CT	TAT	WT	 
//
//	1	0	3	3	3	0
//	2	1	2	5	4	2
//	3	2	1	6	4	3
//	4	3	4	10	7	3
//	5	4	5	15	11	6
//	6	5	2	17	12	10
// Average TAT time : 6.83
// Average waiting time : 1.67
