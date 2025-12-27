#include<iostream>
using namespace std;
const int INF = 1e9;
int minDistance(int dist[],int visited[])
{
    int min = INF, min_index;
    for(int v=0;v<4;v++)
    {
        if(visited[v]==0 && dist[v]<=min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;



}
void dijkstra(int graph[4][4],int dist[],int src,int V,int visited[])
{
    for(int i=0;i<V;i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    for(int count=0;count<V-1;count++)
    {
        int u = minDistance(dist,visited);
        visited[u] = 1;
        for(int v=0;v<V;v++)
        {
            if(!visited[v] && graph[u][v] && dist[u]!=INF && dist[u]+graph[u][v]<dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}


int main()
{
    int graph[4][4] = { { 0, 10, 15, 0 },
                        { 10, 0, 35, 25 },
                        { 15, 35, 0, 30 },
                        { 0, 25, 30, 0 } };
    int V = 4;
    int dist[100];
    int visited[100];
    dijkstra(graph,dist,0,V,visited);
    cout<<"Vertex \t Distance from Source Vertex\n";
    for(int i=0;i<V;i++)
    {
        cout<<i<<"\t"<<dist[i]<<"\n";
    }
    return 0;

}