#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void addEdge(vector<vector<pair<int, int>>> &adjList, int u, int v, int weight)
{
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); // Assuming an undirected graph
}

int primMST(vector<vector<pair<int, int>>> &adjList, int vertices)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(vertices, INT_MAX);
    vector<bool> inMST(vertices, false);

    // Start from vertex 0
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto neighbor : adjList[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    // Calculate the total weight of the minimum spanning tree
    int totalWeight = 0;
    for (int i = 0; i < vertices; i++)
    {
        totalWeight += key[i];
    }

    return totalWeight;
}

int main()
{
    // Create a graph with 5 vertices
    int vertices = 5;
    vector<vector<pair<int, int>>> adjList(vertices);

    // Add edges to the graph with weights
    addEdge(adjList, 0, 1, 2);
    addEdge(adjList, 0, 2, 3);
    addEdge(adjList, 1, 2, 1);
    addEdge(adjList, 1, 3, 1);
    addEdge(adjList, 2, 4, 4);
    addEdge(adjList, 3, 4, 5);

    // Find the minimum spanning tree using Prim's algorithm
    int minWeight = primMST(adjList, vertices);

    cout << "Total weight of the minimum spanning tree: " << minWeight << endl;

    return 0;
}
