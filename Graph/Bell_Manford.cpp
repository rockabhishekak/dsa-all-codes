#include<iostream>
using namespace std;
const int INF = 1e9;
bool bellmanFord(int graph[][3], int V, int E, int src, int
    dist[])
    {
        for(int i=0;i<V;i++)
        {
            dist[i] = INF;
        }
        dist[src] = 0;
        for(int i=1;i<=V-1;i++)
        {
            for(int j=0;j<E;j++)
            {
                int u = graph[j][0];
                int v = graph[j][1];
                int weight = graph[j][2];
                if(dist[u]!=INF && dist[u]+weight<dist[v])
                {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        for(int i=0;i<E;i++)
        {
            int u = graph[i][0];
            int v = graph[i][1];
            int weight = graph[i][2];
            if(dist[u]!=INF && dist[u]+weight<dist[v])
            {
                return false; // Negative weight cycle detected
            }
        }
        return true;
    }
int main()
{
    int graph[][3] = { {0, 1, -1}, {0, 2, 4},
                       {1, 2, 3}, {1, 3, 2},
                       {1, 4, 2}, {3, 2, 5},
                       {3, 1, 1}, {4, 3, -3} };
    int V = 5; // Number of vertices
    int E = sizeof(graph)/sizeof(graph[0]); // Number of edges
    int dist[100];
    if(bellmanFord(graph,V,E,0,dist))
    {
        cout<<"Vertex \t Distance from Source Vertex\n";
        for(int i=0;i<V;i++)
        {
            cout<<i<<"\t"<<dist[i]<<"\n";
        }
    }
    else
    {
        cout<<"Graph contains negative weight cycle\n";
    }
    return 0;
}