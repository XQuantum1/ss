#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u); // Assuming an undirected graph
}

void dfs(vector<vector<int>> &adjList, int start)
{
    int vertices = adjList.size();
    vector<bool> visited(vertices, false);
    stack<int> s;

    s.push(start);
    visited[start] = true;

    while (!s.empty())
    {
        int current = s.top();
        cout << current << " ";
        s.pop();

        for (int neighbor : adjList[current])
        {
            if (!visited[neighbor])
            {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    // Create a graph with 5 vertices
    int vertices = 5;
    vector<vector<int>> adjList(vertices);

    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);

    // Perform DFS starting from vertex 0
    cout << "DFS starting from vertex 0: ";
    dfs(adjList, 0);

    return 0;
}
