#include<iostream>
using namespace std;
int main()
{
    int V,u,v,e;
    // Input number of vertices and edges
    cout<<"Enter number of vertices:";
    cin>>V;
    int adj[V][V]={0}; // Adjacency matrix initialized to 0
    cout<<"Enter edges (u v): "<<endl;
    cin>>e;
    // Initialize adjacency matrix
    for(int i=0;i<e;i++)
    {
        cout<<"Edge "<<i+1<<": ";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1; // For undirected graph
    }
    // Print adjacency matrix
    cout<<"Adjacency Matrix:"<<endl;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    
}