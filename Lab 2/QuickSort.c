/*QUICK SORT ALGORITHM
Time Complexity : 
Worst Case : 0(n^2)
Best and Average Case : 0(nlogn)
Space Complexity : 0(logn)*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quick_sort(int [], int , int);
int partition(int [], int , int);
void swap(int *, int *);
void print_arr(int [], int);

void main()
{
    int n;
    clock_t start, end;
    double time_taken;

    printf("\nEnter the number of elements to sorted : ");
    scanf("%d",&n);

    printf("\nGenerating %d Random Elements...\n",n);

    srand(time(NULL));
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = rand() % 10000;
    }

    printf("\nSorting the array using Quick Sort...\n");

    start = clock();
    quick_sort(arr, 0, n-1);
    end = clock();

    printf("\nSorted Array\n\n");

    print_arr(arr , n);

    time_taken = ((double) (end - start)/CLOCKS_PER_SEC);

    printf("\nThe time taken to sort %d elements using Quick Sort : %lf Seconds\n",n,time_taken);
}

void quick_sort(int a[], int lb, int ub)
{
    if(lb < ub)
    {
        int loc = partition(a, lb, ub);

        quick_sort(a, lb, loc-1);
        quick_sort(a, loc+1, ub);
    }
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb , end = ub;

    while(start < end)
    {
        while(a[start] <= pivot)
        {
            start++;
        }
        while(a[end] > pivot)
        {
            end--;
        }

        if(start < end)
        {
            swap(&a[start],&a[end]);
        }
        
    }
    swap(&a[lb],&a[end]);

    return end;
}

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(int a[], int n)
{   
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}