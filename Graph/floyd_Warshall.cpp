#include<iostream>
using namespace std;
const int V=4;
const int INF=1e9;
void floydWarshall(int graph[V][V])
{
    int dist[V][V];
    // Initialize the solution matrix same as input graph matrix
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            dist[i][j] = graph[i][j];
        }
    }
    // Add all vertices one by one to the set of intermediate vertices
    for(int k=0;k<V;k++)
    {
        // Pick all vertices as source one by one
        for(int i=0;i<V;i++)
        {
            // Pick all vertices as destination for the above picked source
            for(int j=0;j<V;j++)
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // Print the shortest distance matrix
    cout<<"Shortest distance matrix:"<<endl;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(dist[i][j]==INF)
                cout<<"INF"<<" ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int graph[V][V]={ {0, 3, INF, 5},
                        {2, 0, INF, 4},
                        {INF, 1, 0, INF},
                        {INF, INF, 2, 0} };
    floydWarshall(graph);
    return 0;
    
}