// // Aim : Simulate MVT and MFT.
// Program :- MANAGEMENT WITH FIXED PARTITIONING TECHNIQUE)algorithm.

/*

    ALGORITHM :-
    ----------

    Step1: Start the process.

    Step2: Declare variables.

    Step3: Enter total memory size ms.

    Step4: Allocate memory for os.
                Ms=ms-os;

    Step5: Read the no partition to be divided n Partition size=ms/n.

    Step6: Read the process no and process size.

    Step 7: If process size is less than partition size allot also blocks the process.
            While allocating update memory wastage-external fragmentation.

            if(pn[i]==pn[j])
                f=1;
	        if(f==0)
            {
                if(ps[i]<=siz)
                {
                    extft=extft+size-ps[i];
                    avail[i]=1;
                    count++;
                }
            }

    Step 8: Print the results.

    Step 9 :Stop.

*/

// #include<stdio.h>

// int main()
// {
//     int m,p,s,p1;
//     int m1[4],i,f,f1=0,f2=0,fra1,fra2,s1,pos;

//     printf("Enter the memory size:");
//     scanf("%d",&m);

//     printf("Enter the no of partitions:");
//     scanf("%d",&p);

//     s=m/p;
//     printf("Each partn size is:%d",s);

//     printf("\nEnter the no of processes:");
//     scanf("%d",&p1);
//     pos=m;

//     for( i=0; i < s; ++i )
//     {
//         if(pos > i )
//         {
//             printf("\nThere is no further memory for process%d",i+1);
//             m1[i]=0;
//             break;
//         }
//         else
//         {
//             printf("\nEnter the memory req for process%d:",i+1);
//             scanf("%d",&m1[i]);
            
//             if(m1[i]<=s)
//             {
//                 printf("\nProcess is allocated in partition%d",i+1);
//                 fra1=s-m1[i];

//                 printf("\nInternal fragmentation for process is:%d",fra1);
//                 f1=f1+fra1;
//                 pos=pos-s;
//             }
//             else
//             {
//                 printf("\nProcess not allocated in partition%d",i+1);
//                 s1=m1[i];

//                 while(s1>s)
//                 {
//                     s1=s1-s;
//                     pos=pos-s;
//                 }

//                 pos=pos-s;
//                 fra2=s-s1;
//                 f2=f2+fra2;

//                 printf("\nExternal Fragmentation for this process is:%d",fra2);
//             }
//         }  
//     }
//     printf("\nProcess\tallocatedmemory");
//     for(i=0;i < p1; i++ )
//         printf("\n%5d\t%5d",i+1,m1[i]);

//     f=f1+f2;
//     printf("\nThe tot no of fragmentation is:%d",f);

//     getch();
//     return 0;
// }

#include <stdio.h>

int main()
{
    int i, m, p, s, n, req;

    printf("Enter the memory size: ");
    scanf("%d", &m);

    printf("Enter the no of partitions: ");
    scanf("%d", &p);

    s = m / p;
    printf("Each partition size: %d\n", s);

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0, m -= s; i < n; ++i)
    {
        printf("Enter the memory req for process%d: ", i + 1);
        scanf("%d", &req);

        if (req <= s && m >= s)
        {
            printf("Process1 is allocated in partn%d\n", i + 1);
            printf("Internal fragmentation for process%d is: %d\n", i + 1, s - req);
            m -= s;
        }
        else
        {
            printf("Process2 is not allocated in partn%d\n", i + 1);
            printf("External fragmentation for process%d is: %d\n", i + 1, m - req);
            m -= s;
        }
    }

    return 0;
}

/*

INPUT/OUTPUT:-
------------

Enter the memory size: 80
Enter the no of partitions: 4
Each partition size: 20
Enter the number of processes: 2
Enter the memory req for process1: 18
Process1 is allocated in partn1
Internal fragmentation for process1 is: 2
Enter the memory req for process2: 22
Process2 is not allocated in partn2
External fragmentation for process2 is: 18

*/
