// Topological Ordering
// Time Complexity : O(v + e)
// Space Complexity : O(v + e)

#include<stdio.h>
#define MAX 100

int adj_mat[MAX][MAX], visited[MAX], n, order[MAX], idx;

void dfs(int);
void topological_sort();

void main()
{
    printf("Enter the number of Vertices : ");
    scanf("%d", &n);

    printf("Enter the Adjaceny matrix : \n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d", &adj_mat[i][j]);
        }
    }

    topological_sort();

    printf("Topologoical ordering of vertices : ");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ", order[i]);
    }
    printf("\n");
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
        {
            dfs(i);
        }
    }
}

void dfs(int v)
{
    visited[v] = 1;

    for(int i = 0 ; i < n ; i++)
    {
        if(adj_mat[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
    order[--idx] = v;
}