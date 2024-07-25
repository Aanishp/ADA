/*selction Sort
Time Complexity : 0(n^2)
Space Complexity : 0(n)*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *, int *);
void selection_sort(int [], int );
void print_arr(int [], int );

void main()
{ 
	clock_t start, end;
  	double time_taken;
  	int n;
  
  	printf("\nEnter the number of elements to be sorted : ");
	scanf("%d",&n);

	printf("\nGenerating %d random elements...\n",n);

	int arr[n];

	srand(time(NULL));

	for(int i = 0 ; i < n ; i++)
	{
		arr[i] = rand() % 10000;
	}

	printf("\nSorting the array using Selection Sort...\n");

	start = clock();
	selection_sort(arr,n);
	end = clock();

	printf("\nSorted Array\n\n");

	print_arr(arr,n);

	time_taken = ((double) (end - start)/CLOCKS_PER_SEC);

	printf("\nTime taken to sort %d elements : %lf seconds\n",n,time_taken);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int a[], int n)
{
	for(int i = 0 ; i < n-1 ; i++)
	{
		int min = i;
		for(int j = i+1 ; j < n ; j++)
		{
			if(a[min] > a[j])
			{
				min = j;
			}
		}
		if(min != i)
		{
			swap(&a[min],&a[i]);
		}
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