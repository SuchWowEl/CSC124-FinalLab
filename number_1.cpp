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

const int MAX_SIZE = 10;
const int INF = numeric_limits<int>::max();

struct Edge
{
	bool exists;
	int weight;
};

bool hasEdge(Edge matrix[][MAX_SIZE], int v1, int v2)
{
	return matrix[v1][v2].exists;
}

int getEdgeWeight(Edge matrix[][MAX_SIZE], int v1, int v2)
{
	return matrix[v1][v2].weight;
}

int numberOfEdges(Edge matrix[][MAX_SIZE], int MAX_SIZE)
{
	int count = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (matrix[i][j].exists)
			{
				count++;
			}
		}
	}
	return count;
}

void dijkstraShortestPaths(Edge matrix[][MAX_SIZE], int startVertex)
{
	int dist[MAX_SIZE];
	int prev[MAX_SIZE];
	bool visited[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++)
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

		for (int v = 0; v < MAX_SIZE; v++)
		{
			if (hasEdge(matrix, u, v))
			{
				int weight = getEdgeWeight(matrix, u, v);
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

	cout << "Shortest paths from vertex " << startVertex << ":\n";
	for (int v = 0; v < MAX_SIZE; v++)
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
				int path[MAX_SIZE];
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

int main()
{
	Edge matrix[MAX_SIZE][MAX_SIZE] = {
		{{false, 0}, {true, 2}, {false, 0}, {true, 20}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 1}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
		{{true, 3}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {true, 4}, {false, 0}, {false, 0}, {true, 6}, {true, 4}, {false, 0}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {true, 7}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 3}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {true, 1}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 1}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 2}, {false, 0}, {false, 0}, {false, 0}, {true, 2}},
		{{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 2}, {false, 0}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 1}, {false, 0}}};

	/*
	Edge matrixNoWeight[MAX_SIZE][MAX_SIZE] = {
		{0, 1, 0, 1, 0, 0, 0, 0, 0, 0}
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		{0, 0, 1, 0, 0, 1, 1, 0, 0, 0}
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0}
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0}
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0}
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0}
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
	};
	*/

	int numEdges = numberOfEdges(matrix, MAX_SIZE);
	cout << "The number of edges in the graph is " << numEdges << ".\n \n";

	int startVertex = 0;
	dijkstraShortestPaths(matrix, startVertex);
	return 0;
}
