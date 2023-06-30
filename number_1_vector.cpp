/* MEMBERS:
    Guingao, Rhea Salve
    Dolorosa, Elizer
    Aclo, Romeo Giullano
*/

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

int numberOfEdges(vector<vector<int>> graph)
{
    int count = 0;
    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph[i].size(); j++)
            if (graph[i][j] > 0)
                count++;
    return count;
}

int numberOfEdges(vector<vector<bool>> graph)
{
    int count = 0;
    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph[i].size(); j++)
            if (graph[i][j] > 0)
                count++;
    return count;
}

void dijkstraShortestPaths(vector<vector<int>> graph, int startVertex)
{
    int dist[graph.size()];
    int prev[graph.size()];
    bool visited[graph.size()];

    for (int i = 0; i < graph.size(); i++)
    {
        dist[i] = numeric_limits<int>::max();
        prev[i] = -1;
        visited[i] = false;
    }

    dist[startVertex] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startVertex});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int uDist = pq.top().first;
        pq.pop();

        if (uDist > dist[u])
        {
            continue;
        }

        visited[u] = true;

        for (int v = 0; v < graph.size(); v++)
        {
            int temp = graph[u][v];
            if (temp > 0)
            {
                int weight = temp;
                int newDist = dist[u] + weight;
                if (newDist < dist[v])
                {
                    dist[v] = newDist;
                    prev[v] = u;
                    if (!visited[v])
                    {
                        pq.push({newDist, v});
                    }
                }
            }
        }
    }

    cout << "Shortest paths from vertex " << 1 << ":\n";
    for (int v = 0; v < graph.size(); v++)
    {
        if (v != startVertex)
        {
            cout << "Vertex " << v + 1 << ": ";
            if (dist[v] == numeric_limits<int>::max())
            {
                cout << "No path found.";
            }
            else
            {
                int path[graph.size()];
                int pathLength = 0;
                int currVertex = v;
                while (currVertex != -1)
                {
                    path[pathLength++] = currVertex;
                    currVertex = prev[currVertex];
                }
                for (int i = pathLength - 1; i >= 0; i--)
                {
                    cout << path[i] + 1;
                    if (i > 0)
                    {
                        cout << " -> ";
                    }
                }
                cout << " (length = " << dist[v] << ")";
            }
            cout << endl;
        }
    }
}

bool isGraphConnected(vector<vector<int>> matrix, int startVertex)
{
    startVertex += 1;
    bool visited[matrix.size()] = {false};

    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < matrix.size(); v++)
        {
            if (matrix[u][v] > 0 && !visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }

    return true;
}

void bfs(const vector<vector<int>> &graph, int startNode)
{
    startNode -= 1;
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    queue<int> bfsQueue;

    visited[startNode] = true;
    bfsQueue.push(startNode);

    while (!bfsQueue.empty())
    {
        int currentNode = bfsQueue.front();
        bfsQueue.pop();
        cout << currentNode + 1 << " ";

        for (int i = 0; i < numNodes; ++i)
        {
            if (!visited[i] && graph[currentNode][i] != 0)
            {
                visited[i] = true;
                bfsQueue.push(i);
            }
        }
    }
}

void dfsUtil(vector<vector<int>> &matrix, int vertex, vector<bool> &visited)
{
    visited[vertex] = true;
    cout << vertex + 1 << " ";

    for (int i = 1; i <= matrix.size() - 1; i++)
    {
        // cout << "w " << i << endl;
        if (matrix[vertex][i] != 0 && !visited[i])
        {
            dfsUtil(matrix, i, visited);
        }
    }
}

void dfs(vector<vector<int>> &matrix, int startVertex)
{
    // startVertex -= 1;
    vector<bool> visited(matrix.size(), false);
    dfsUtil(matrix, startVertex, visited);
}

int main()
{
    vector<vector<int>> graph = {
        {0, 2, 0, 20, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 8, 0, 0, 6, 4, 0, 0, 0},
        {0, 0, 7, 0, 0, 0, 0, 3, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};

    vector<vector<bool>> booleanGraph = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};

    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "3. a.)" << endl;
    int startVertex = 0;
    dijkstraShortestPaths(graph, startVertex);
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;

    cout << "3. b.)" << endl;
    cout << "Is the directed graph connected? " << boolalpha << isGraphConnected(graph, startVertex) << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

    cout << "3. c.)" << endl;
    cout << "Breadth-first spanning tree starting at vertex 1: " << endl;
    bfs(graph, 1);
    cout << "\n-------------------------------------------------------------------------------------------------------------" << endl;

    cout << "3. d.)" << endl;
    cout << "Depth-first spanning tree starting at vertex 1: " << endl;
    dfs(graph, 0);
    cout << "\n-------------------------------------------------------------------------------------------------------------" << endl;

    cout << "Bonus Question #2:" << endl;
    int numEdges = numberOfEdges(booleanGraph);
    cout << "The number of edges in the graph is " << numEdges << ".\n ";
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

    return 0;
}
