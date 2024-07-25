#include<stdio.h>

void findSubset(int [], int , int , int [], int , int);

void main()
{
    int S[] = {1,2,5,6,8}, n = sizeof(S) / sizeof(S[0]), d = 9, subset[n], size = 0, sum = 0;

    printf("Given items in the subset : {");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d", S[i]);

        if (i != n-1)
            printf(",");
    }
    printf("}\n");

    printf("The desirable Sum : %d\n",d);

    printf("The following are the subsetsets found : \n");

    findSubset(S,n,d,subset,size,sum);

    if(size == 0)
    {
        printf("\nNo subsets are found\n");
    }
}

void findSubset(int S[], int n, int d, int subset[], int size, int sum)
{
    if(d == sum)
    {
        printf("{");
        for(int i = 0 ; i < size ; i++)
        {
            printf("%d",subset[i]);
            if(i != size - 1)
            {
                printf(",");
            }
        }
        printf("}\n");
        return;
    }

    if(sum > d || n == 0)
    {
        return;
    }

    subset[size] = S[0];

    findSubset(S+1,n-1,d,subset,size+1,sum+S[0]);
    findSubset(S+1,n-1,d,subset,size,sum);
}