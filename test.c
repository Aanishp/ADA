#include<stdio.h>
#define MAX 100

int adj_mat[MAX][MAX], visited[MAX], order[MAX], n , idx;

void topological_sort();
void dfs(int);

void main()
{
    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    printf("Enter the adjaceny matrix : \n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d", &adj_mat[i][j]);
        }
    }

    topological_sort();

    printf("The order of topological Sort : ");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",order[i]);
    }
}

void topological_sort()
{
    idx = n;

    for(int i = 0 ; i < n ; i++)
    {
        visited[i] = 0;
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(!visited[i])
            dfs(i);
    }
}

void dfs(int v)
{   
    visited[v] = 1;

    for(int i = 0 ; i < n ; i++)
    {
        if(!visited[i] && adj_mat[v][i])
        {
            dfs(i);
        }
    }
    order[--idx] = v;
}