#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, start;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10] = {0};

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter starting vertex: ";
    cin >> start;

    // DFS
    int visited[10] = {0};

    cout << "DFS: ";
    void (*dfs)(int);

    // Recursive DFS
    auto DFS = [&](auto&& self, int v) -> void {
        visited[v] = 1;
        cout << v << " ";

        for (int i = 0; i < n; i++)
            if (graph[v][i] && !visited[i])
                self(self, i);
    };

    DFS(DFS, start);

    // BFS
    int visited2[10] = {0};
    queue<int> q;

    q.push(start);
    visited2[start] = 1;

    cout << "\nBFS: ";

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] && !visited2[i])
            {
                q.push(i);
                visited2[i] = 1;
            }
        }
    }

    return 0;
}