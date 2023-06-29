/* MEMBERS:
	Guingao, Rhea Salve
	Dolorosa, Elizer
	Aclo, Romeo Giullano
*/

#include <iostream>
#include <limits>
using namespace std;

const int MAX_SIZE = 10;

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

int main()
{
	Edge matrix[MAX_SIZE][MAX_SIZE] = {
		{{false, 0}, {true, 2}, {false, 0}, {true, 20}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 1}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
		{{true, 3}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {true, 4}, {false, 0}, {false, 0}, {true, 6}, {true, 4}, {false, 0}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {true, 3}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 3}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {true, 1}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 1}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 2}},
		{{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 2}, {false, 0}, {false, 0}, {false, 0}},
		{{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {true, 1}, {false, 0}}};

	int numEdges = numberOfEdges(matrix, MAX_SIZE);
	cout << "The number of edges in the graph is " << numEdges << ".";

	return 0;
}
