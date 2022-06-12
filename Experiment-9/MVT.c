// Aim : Simulate MVT and MFT.
// Program : MVT MEMORY MANAGEMENT TECHNIQUE

/*

Algorithm :-
----------

step-1: start.

step-2: declare ms,mp[10],i,temp,n of integer data type and ch of character
        data type. Then initalize n with zero and ch with character 'y'.

step-3: Read the total available memory into ms and assign temp with value of 
        ms.

step-4: Initalize i with zero and while ch == 'y' increment i and n values and do,
            (a) Read the memory required for process into mp[i].
            (b) if mp[i] is lesser than or equal temp then,
                    (i) print "memory allocated for the process" and,
                    (ii) assign temp = temp - mp[i].
                else
                    (i) print "Memory is full" and,
                    (ii) goto step-5.
            (c) ask if they want to continue or not and store the input respose into ch.

step-5: Display total memory and the memory allocated to each process.

step-6: Calulate and display Total Memory Allocated and Total External Fragmentation.

step-7: stop.

*/

#include <stdio.h>

int main()
{
    int ms,mp[10],i,temp,n=0;
    char ch = 'y';
    
    printf("\nEnter the total memory available (in Bytes)-- ");
    scanf("%d",&ms);
    temp=ms;

    for(i=0;ch=='y';i++,n++)
    {
        printf("\nEnter memory required for process %d (in Bytes) -- ",i+1);
        scanf("%d",&mp[i]);
        
        if(mp[i]<=temp)
        {
            printf("\nMemory is allocated for Process %d ",i+1);
            temp = temp - mp[i];
        }
        else
        {
            printf("\nMemory is Full");
            break;
        }
        
        printf("\nDo you want to continue(y/n) -- ");
        scanf(" %c", &ch);
    }

    printf("\n\nTotal Memory Available -- %d", ms);
    printf("\n\n\tPROCESS\t\t MEMORY ALLOCATED ");
    for(i=0;i<n;i++)
        printf("\n \t%d\t\t%d",i+1,mp[i]);

    printf("\n\nTotal Memory Allocated is %d",ms-temp);
    printf("\nTotal External Fragmentation is %d",temp);

    getchar();
    return 0;
}

/*

INPUT/OUTPUT :-
------------

Enter the total memory available (in Bytes) -- 1000
Enter memory required for process 1 (in Bytes) -- 400
Memory is allocated for Process 1
Do you want to continue(y/n) -- y
Enter memory required for process 2 (in Bytes) -- 275
Memory is allocated for Process 2
Do you want to continue(y/n) -- y
Enter memory required for process 3 (in Bytes) -- 550
Memory is Full
Total Memory Available -- 1000
PROCESS             MEMORY-ALLOCATED
1                        400
2                        275
Total Memory Allocated is 675

Total External Fragmentation is 325

*/