// Aim :- Implementation of the following Memory Allocation Methods for fixed partition
//              a) Worst-fit    b) Best-fit     c) First-fit

// Program :- b) Best-Fit

/*

    Algorithm:-
    ---------

    step-1: start.

    step-2: declare an constant MAX of value 25 globally.

    step-3: declare frag[MAX],b[MAX],f[MAX],i,j,nb,nf,temp,lowest of
            integer data type and bf[MAX],ff[MAX] of also static interger
            data type. And initalize lowest = 10000.

    step-4: Read number of blocks into nb and number of files into nf,
            then read size of each block into array b[] and read 
            the size of each file into array f[].

    step-5: for i = 1 to nf do,
                (a) for j = 1 to nb do,
                    if bf[j] is not equal to 1 then,
                        (1) assgin temp = b[j]-f[i] and,
                        (2) if temp is greater than or equal to zero then,
                            if lowest is greater than temp then,
                                (i) assign ff[i] = j and,
                                (ii) assign lowest = temp.
                (b) assign frag[i] = lowest.
                (c) assign bf[ff[i]] = 1.
                (d) assign lowest = 10000.

    step-6: Display File no, File size, Block no, Block size, Fragement
            values in form of a table.

    step-7: stop

*/

// Source code :-
// -----------

#include <stdio.h>
#define MAX 25

int main()
{
    int frag[MAX],b[MAX],f[MAX],i,j,nb,nf,temp,lowest=10000;
    static int bf[MAX],ff[MAX];

    printf("\n\tMemory Management Scheme - Best Fit");

    printf("\nEnter the number of blocks:");
    scanf("%d",&nb);

    printf("Enter the number of files:");
    scanf("%d",&nf);

    printf("\nEnter the size of the blocks:-\n");
    for(i=1;i<=nb;i++)
    {
        printf("Block %d:",i);
        scanf("%d",&b[i]);
    }

    printf("Enter the size of the files :-\n");
    for(i=1;i<=nf;i++)
    {
        printf("File %d:",i);
        scanf("%d",&f[i]);
    }

    for(i=1;i<=nf;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];

                if(temp>=0)
                    if(lowest>temp)
                    {
                        ff[i]=j;
                        lowest=temp;
                    }
            }
        }
    
        frag[i]=lowest;
        bf[ff[i]]=1;
        lowest=10000;
    }

    printf("\nFile No\tFile Size \tBlock No\tBlock Size\tFragment");
    for(i=1;i<=nf && ff[i]!=0;i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
    
    getchar();
    return 0;
}

/*
    INPUT/OUTPUT :-
    -------------

    Memory Management Scheme - Best Fit

    Enter the number of blocks: 3
    Enter the number of files: 2

    Enter the size of the blocks:-
    Block 1: 5
    Block 2: 2
    Block 3: 7

    Enter the size of the files:-
    File 1: 1
    File 2: 4

    File No                  File Size               Block No             Block Size           Fragment
    1                        1                       2                    2                    1
    2                        4                       1                    5                    1

*/
