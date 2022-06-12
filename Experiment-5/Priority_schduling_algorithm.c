// Aim : Simulate the following CPU scheduling algorithm
//          (a)Round Robin      (b)Priority

// Program : Priority CPU scheduling algorithm

/*

Algorithm :-
---------

step-1: start

step-2: declare temp,n,p[10],pp[10],pt[10],w[10],t[10],i as integer
        datatypes and awt,atat as float datatypes.

step-3: read the number of processes to n and read the burst time
        and priority of the processes.

step-4: sort the processes according to the priority by assigning
        temp = p[j], p[j] = p[i], p[i] = temp, and their burst time
        and priority if(pp[i]>pp[j]) until i < n-1 and j < n as 
        they are initalized as i = 0 and j = i+1.

step-5: Assign value as,
            w[0]=0;
            awt=0;
            t[0]=pt[0];
            atat=t[0];

step-6: calculate the total waiting time and turn around time using
        a loop, for(i=1;i<n;i++)

step-7: print the Process, Burst Time, Waiting Time, Turn Around Time,
        Priority as a table.

step-8: Calculate and display the average waiting time and average
        turn around time.

step-9: stop.

*/

/*
    Note :-
    -----

            Here, The priority increases as the priority number decreases
        i.e, Lower the given priority number greater it's priority...
*/

// Source Code :
#include <stdio.h>

int main()
{
    int  temp,n,p[10],pp[10],pt[10],w[10],t[10],i;
    float awt,atat;

    printf("Enter the number of process : ");
    scanf("%d",&n);

    printf("\nEnter process : time priorities \n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter the burst time of Process no %d : ",i+1);
        scanf("%d",&pt[i]);
        printf("Enter the Priority of Process no %d : ",i+1);
        scanf("%d",&pp[i]);
        p[i]=i+1;
    }

    for(i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(pp[i]>pp[j])
            {
                temp=pp[i];
                pp[i]=pp[j];
                pp[j]=temp;

                temp=pt[i];
                pt[i]=pt[j];
                pt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    w[0]=0;
    awt=0;
    t[0]=pt[0];
    atat=t[0];
    
    for(i=1;i<n;i++)
    {
        w[i]=t[i-1];
        awt+=w[i];
        t[i]=w[i]+pt[i];
        atat+=t[i];
    }

    printf("\n\n Process \t Burst Time \t Waiting Time \t Turn Around Time   Priority \n");
    for(i=0;i<n;i++)
        printf("\n %d \t\t %d  \t\t %d \t\t %d \t\t %d \n",p[i],pt[i],w[i],t[i],pp[i]);

    awt /= (float)n;
    atat /= (float)n;
    printf("\n Average Waiting Time : %.2f \n",awt);
    printf("\n Average Turn Around Time : %.2f \n",atat);

    getchar();
    return 0;
}

/*

INPUT/OUTPUT :-
------------

Enter the number of process : 4

Enter process : time priorities 

Enter the burst time of Process no 1 : 3
Enter the Priority of Process no 1 : 1

Enter the burst time of Process no 2 : 4
Enter the Priority of Process no 2 : 2

Enter the burst time of Process no 3 : 5
Enter the Priority of Process no 3 : 3

Enter the burst time of Process no 4 : 6
Enter the Priority of Process no 4 : 4


 Process         Burst Time      Waiting Time    Turn Around Time   Priority 

 1               3               0               3               1 

 2               4               3               7               2 

 3               5               7               12              3 

 4               6               12              18              4 

 Average Waiting Time : 5.50 

 Average Turn Around Time : 10.00

 */