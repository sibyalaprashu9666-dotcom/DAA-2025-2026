#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, mincost = 0;
    int cost[10][10], visited[10] = {0};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    visited[0] = 1;

    cout << "Minimum Spanning Tree:\n";

    for (int e = 0; e < n - 1; e++)
    {
        int min = INT_MAX, a = -1, b = -1;

        for (int i = 0; i < n; i++)
            if (visited[i])
                for (int j = 0; j < n; j++)
                    if (!visited[j] && cost[i][j] != 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }

        if (b == -1)
        {
            cout << "Graph is not connected";
            return 0;
        }

        cout << a << " - " << b << " : " << min << endl;
        mincost += min;
        visited[b] = 1;
    }

    cout << "Minimum Cost = " << mincost;

    return 0;
}