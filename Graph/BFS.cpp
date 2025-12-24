#include<iostream>
using namespace std;
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;
int visited[MAX];

void enqueue(int value)
{
    if(rear == MAX - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }
    if(front == -1)
        front = 0;

    queue[++rear] = value;
}

int dequeue()
{
    if(front == -1 || front > rear)
    {
        return -1;
    }
    return queue[front++];
}

void BFS(int start, int V, int adj[MAX][MAX])
{
    front = rear = -1;

    for(int i=0;i<V;i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while(front != -1 && front <= rear)
    {
        int current = dequeue();
        cout << current << " ";

        for(int i=0;i<V;i++)
        {
            if(adj[current][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
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

    for(int i=0;i<e;i++)
    {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
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
        cout << "Invalid starting vertex\n";
        return 0;
    }

    cout << "BFS Traversal: ";
    BFS(start_vertex, V, adj);

    return 0;
}
