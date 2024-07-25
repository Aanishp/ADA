/*Prim's Algorithm
Time Complexity : O((v+e)logv)
Space Comlexity : O(v+e)*/

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 5

int min_key(int [], bool []);
void print_mst(int [], int [V][V]);
void prim_mst(int [V][V]);

void main()
{
    int graph[V][V] = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    prim_mst(graph);
}

int min_key(int key[], bool mst_set[])
{
    int min = INT_MAX, min_idx;

    for(int v = 0 ; v < V ; v++)
    {
        if(mst_set[v] == false && key[v] < min)
        {
            min = key[v];
            min_idx = v;
        }
    }
    return min_idx;
}

void print_mst(int parent[] , int graph[V][V])
{
    printf("Edges\tWeights\n");

    for(int i = 1 ; i < V ; i++ )
    {
        printf("%d - %d\t%d\n",parent[i],i,graph[i][parent[i]]);
    }
}

void prim_mst(int graph[V][V])
{
    int parent[V], key[V]; 
    bool mst_set[V];

    for(int i = 0 ; i < V ; i++)
    {
        key[i] = INT_MAX;
        mst_set[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0 ; count < V-1 ; count++)
    {
        int u = min_key(key,mst_set);
        mst_set[u] = true;

        for(int v = 0 ; v < V ; v++)
        {
            if(graph[u][v] && mst_set[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    print_mst(parent,graph);
}