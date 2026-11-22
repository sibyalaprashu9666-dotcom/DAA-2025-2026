#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

int parent[10];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

int main()
{
    int n, e, mincost = 0;
    Edge edge[20];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;

    sort(edge, edge + e, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    for (int i = 0; i < n; i++)
        parent[i] = i;

    cout << "Minimum Spanning Tree:\n";

    for (int i = 0, count = 0; i < e && count < n - 1; i++)
    {
        int u = find(edge[i].u);
        int v = find(edge[i].v);

        if (u != v)
        {
            cout << edge[i].u << " - " << edge[i].v
                 << " : " << edge[i].w << endl;

            mincost += edge[i].w;
            parent[u] = v;
            count++;
        }
    }

    cout << "Minimum Cost = " << mincost;

    return 0;
}