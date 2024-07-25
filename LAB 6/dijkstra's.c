// Dijkstra's Algorithm
// Time Complexity : O(v^2)
// Space Complexity : O(v^2)

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

#define V 6

int min_dist(int [], bool []);
void dijkstra(int [V][V], int);
void print_shortest_path(int []);

void main()
{
    int graph[V][V] = {
        {0, 4, 8, 0, 0, 7},
        {4, 0, 6, 5, 9, 4},
        {8, 6, 0, 1, 3, 0},
        {0, 5, 1, 0, 2, 4},
        {0, 9, 3, 2, 0, 8},
        {7, 4, 0, 4, 8, 0}
    };

    dijkstra(graph, 0);
}

int min_dist(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_idx;

    for(int i = 0 ; i < V ; i++)
    {
        if(sptSet[i] == false && dist[i] < min)
        {
            min = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void dijkstra(int graph[V][V], int source)
{
    int dist[V];
    bool sptSet[V];

    for(int i = 0 ; i < V ; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[source] = 0;

    for(int i = 0 ; i < V-1 ; i++)
    {
        int u = min_dist(dist,sptSet);

        sptSet[u] = true;

        for(int v = 0 ; v < V; v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print_shortest_path(dist);
}

void print_shortest_path(int dist[V])
{
    printf("Vertex \t\t Distance from Source\n");
    for(int i = 0 ; i < V ; i++)
    {
        printf("%d \t\t\t\t %d\n",i, dist[i]);
    }
}