#include <iostream>
#include <climits>
using namespace std;

int n, cost[10][10], visited[10] = {0};
int mincost = INT_MAX;

void tsp(int city, int count, int total)
{
    if (count == n && cost[city][0] != 0)
    {
        mincost = min(mincost, total + cost[city][0]);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && cost[city][i] != 0)
        {
            visited[i] = 1;
            tsp(i, count + 1, total + cost[city][i]);
            visited[i] = 0;
        }
    }
}

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    visited[0] = 1;
    tsp(0, 1, 0);

    if (mincost == INT_MAX)
        cout << "Tour not possible";
    else
        cout << "Minimum Cost = " << mincost;

    return 0;
}