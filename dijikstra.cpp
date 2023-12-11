#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main()
{
    cout << "no. of vertices, edges, starting vertex :";
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(n + 1, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto neighbor : adj[u])
        {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest path from source " << s << " to all other vertices:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << ": " << dist[i] << "\n";
    }

    return 0;
}
