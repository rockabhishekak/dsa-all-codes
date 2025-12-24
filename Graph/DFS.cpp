#include<iostream>
using namespace std;
#define MAX 100
int stack[MAX];
int top = -1;
int visited[100];
void push(int value)
{
    if(top == MAX-1)
    {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = value;
}
int pop()
{
    if(top == -1)
    {
        return -1;
    }
    return stack[top--];
}
void DFS(int start, int V, int adj[MAX][MAX])
{
    for(int i=0;i<V;i++)
        visited[i] = 0;

    push(start);
    visited[start] = 1;

    while(top != -1)
    {
        int current = pop();
        cout << current << " ";

        for(int i=V-1;i>=0;i--)
        {
            if(adj[current][i] == 1 && visited[i] == 0)
            {
                push(i);
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int V, u, v, e;
    int adj[MAX][MAX] = {0};

    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v): \n";
    for(int i=0;i<e;i++)
    {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }
    cout<<"Adjacency Matrix:\n";
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    int start_vertex;
    cout << "Enter starting vertex: ";
    cin >> start_vertex;
    if(start_vertex < 0 || start_vertex >= V)
    {
        cout << "Invalid starting vertex.\n";
        return 0;
    }
    cout << "DFS Traversal starting from vertex " << start_vertex << ":\n";
    DFS(start_vertex, V, adj);
    return 0;
}