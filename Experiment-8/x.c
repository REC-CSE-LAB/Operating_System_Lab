// Aim:-  Simulate Bankers Algorithm for Dead Lock Prevention.

/*

ALGORITHM:
1.	Start
2.	Read the number of processes to n.
3.	read the number of resources to r.
4.	read the allocation matrix to alloc.
5.	read the max matrix to max
6.	read the available matrix to avail
7.	for each I and j from 0to n do
                     need[i][j] as difference of max[i][j] and all[i][j]
8.	repeat 
a.	for each I from 0 to n and initialize flag to 0.
i.	if finish[i] is equal to zero.
          1. for each j from 0 to r step 1 do 
                                     if need[i] [j] is less than or equal to avail[j] then
                                                                              continue goto 1
                                                              else
                                                                           break goto 2
                                   2. if j is equal to r
                                           for j from 0 to r step 1 do
                                                    avail[j]+=all[i][j]
                                            assign f as 1
                                            ss[p++]=i+1
                                            increment e by 1.
                                            assign 1 to finish[i].
                b. if f is equal to 0  or e is equal to n then,
                             goto  9
 9.if f is equal to 0 then
                        write the system is in deadlock.
     Else
                       Write the safe sequence which in ss.
10.Stop.


*/

//  PROGRAM:

#include<stdio.h>

int main()
{
    int alloc[10][10],max[10][10],need[10][10],avail[10];
    int work[10],finish[10]={0},i,n,j,r,c=0,p=0,ss[10],f;

    printf("enter no of processes : ");
    scanf("%d",&n);

    printf("enter the no. of resources : ");
    scanf("%d",&r);

    printf("enter the allocation matrix : ");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);    /*reading max matrix*/
    
    printf("enter max matrix : ");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);

    printf("enter available matrix : ");
    for(j=0;j<r;j++)
        scanf("%d",&avail[j]);
    
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            need[i][j]=max[i][j];/*assign max matrix to need */

    while(1)
    {  
        for(f=0,i=0;i<n;i++)
        {
            if(finish[i]==0)
                continue;
            else
                break;
        }
        if(j==r)
        {
            for(j=0;j<r;j++)
            {
                avail[j]+=alloc[i][j];
                f=1;
                finish[i]=1;
                ss[p++]=i+1;
                c++;
            }
        }
        if(f==0)
            break;
        if(f==0 ||c==n)
            break;
        else
        {  
            printf("safe sequence is:");
            for(i=0;i<n;i++)                /*printing safe sequence*/
                printf("%d",ss[i]);
        }
    }
    getchar();
}

/*
        
INPUT/OUTPUT:
  1. Enter no.of processes  5
      Enter no.of resources 3
      Enter allocation matrix
        0   1   0
        2   0   0
        3   0   2
        2   1   1
        0   0   2
     Enter max matrix
         7    5    3         
         3    2    2      
         9    0    2                 
         2    2    2          
         4    3    3
     Enter available matrix
             3        3        2
     The safe sequence is :2       4        5       1         3


2. Enter no.of processes  3
    Enter no.of resources 3
    Enter allocation matrix
        1    0   0
        6    1   2 
        2    1   1
   Enter max matrix
        3     2    2
        6     1    3
        3     1    4
  Enter available matrix
          0     1      1
  The safe sequence is :  2   3     1


3. Enter no.of processes  2
    Enter no.of resources 2
    Enter allocation matrix
        0   1   
        2   0
    Enter max matrix 
         7    5
         3    2
   Enter available matrix 
         3       3
   The system is in DEADLOCK STATE.

*/