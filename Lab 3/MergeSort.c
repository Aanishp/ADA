/*Merge Sort Algorithm
Time Complexity : o(nlogn)
Space Complexity : o(n)*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge_sort(int [], int , int);
void merge(int [], int , int , int);
void print_arr(int [] , int);

void main()
{
    int n;
    clock_t start, end;
    double time_taken;

    printf("\nEnter the number of elements to be sorted : ");
    scanf("%d",&n);

    printf("\nGenerating %d random elements...\n",n);

    srand(time(NULL));

    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = rand() % 10000;
    }

    printf("\nSorting the array using Merge Sort\n");

    start = clock();
    merge_sort(arr, 0, n-1);
    end = clock();

    printf("\nSorted Array\n\n");

    print_arr(arr , n);

    time_taken = ((double) (end-start)/CLOCKS_PER_SEC);

    printf("\nTime taken to sort %d elements using Merge Sort : %lf seconds\n",n,time_taken);
}

void merge_sort(int a[], int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb+ub)/2;

        merge_sort(a, lb, mid);
        merge_sort(a, mid+1, ub);

        merge(a, lb, mid, ub);
    }
}

void merge(int a[], int lb, int mid, int ub)
{
    int i = lb , j = mid+1 , k = 0 , temp[ub-lb+1];

    while(i <= mid && j <= ub)
    {
        if(a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    
    while(i <= mid)
    {
        temp[k++] = a[i++];
    }

    while(j <= ub)
    {
        temp[k++] = a[j++];
    }
        

    for(i = lb , k = 0 ; i <= ub ; i++, k++)
    {
        a[i] = temp[k];
    }
}

void print_arr(int a[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}