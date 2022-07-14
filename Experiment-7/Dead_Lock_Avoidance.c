#include <stdio.h>

int main()
{
    int n, m, r, i, j, k;
    printf("Enter the number of processes : ");
    scanf("%d", &n);

    printf("Enter the number of resources : ");
    scanf("%d", &r);

    int alloc[n][r], max[n][r], avail[r], need[n][r];
    int f[n], ans[n], ind = 0, y = 0;

    puts("Enter the allocation matrix :-");
    for (i = 0; i < n; ++i)
        for (j = 0; j < r; ++j)
            scanf("%d", &alloc[i][j]);

    puts("Enter the max matrix :-");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    puts("Enter the available matrix :-");
    for (j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    // Initializing the finished array with zero
    for (k = 0; k < n; k++)
        f[k] = 0;

    // Calculating the need value
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's Algorithm
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < r; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[n - 1]);
    }

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
