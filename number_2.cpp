#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/* MEMBERS:
	Guingao, Rhea SalveAS
	Dolorosa, Elizer
	Aclo, Romeo Giullano
*/

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

int findParent(std::vector<int>& parent, int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent, parent[vertex]);
}

void unionSets(std::vector<int>& parent, int x, int y) {
    int parentX = findParent(parent, x);
    int parentY = findParent(parent, y);
    parent[parentX] = parentY;
}

void minimumSpanningTree(const std::vector<Edge>& edges, int n) {
    std::vector<Edge> minimumSpanningTree;
    std::vector<int> parent(n, -1);
    int edgeCount = 0;

    std::vector<Edge> sortedEdges = edges;
    std::sort(sortedEdges.begin(), sortedEdges.end(), compareEdges);

    for (const auto& edge : sortedEdges) {
        int parentSrc = findParent(parent, edge.src);
        int parentDest = findParent(parent, edge.dest);

        if (parentSrc != parentDest) {
            minimumSpanningTree.push_back(edge);
            unionSets(parent, parentSrc, parentDest);
            edgeCount++;
        }

        if (edgeCount == n - 1)
            break;
    }

    if (edgeCount == n - 1) {
        std::cout << "Minimum Spanning Tree:\n";
        for (const auto& edge : minimumSpanningTree)
            std::cout << edge.src << " -- " << edge.dest << " with weight " << edge.weight << "\n";
    } else {
        std::cout << "Network has no spanning tree.\n";
    }
}

struct Graph {

  int** adjMatrix;
  int numVertices;

    void bfs(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 1; i <= numVertices; i++)
            visited[i] = false;

        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (int i = 1; i <= numVertices; i++) {
                if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        delete[] visited;
    }

  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new int*[numVertices];
    for (int i = 1; i <= numVertices; i++) {
      adjMatrix[i] = new int[numVertices];
      for (int j = 1; j <= numVertices; j++)
        adjMatrix[i][j] = 0;
    }
  }

  // Add edges
  void addEdge(int i, int j, int weight) {
    adjMatrix[i][j] = weight;
    adjMatrix[j][i] = weight;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = 0;
    adjMatrix[j][i] = 0;
  }

  // Print the martix
  void toString() {
      cout <<  "\t";
    for (int i = 1; i <= numVertices; i++) {
        cout << i << "\t";
    }
    cout << endl;
    cout << "----------------------------------------------------------------------------";
    cout << endl;
    for (int i = 1; i <= numVertices; i++) {
      cout << i << "| \t";
      for (int j = 1; j <= numVertices; j++)
        cout << adjMatrix[i][j] << "\t";
      cout << "\n";
    }
  }

  ~Graph() {
    for (int i = 1; i <= numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};





int main() {

    cout << endl;

    Graph g(8);

    g.addEdge(1, 2, 2);
    g.addEdge(1, 5, 22);
    g.addEdge(1, 6, 8);
    g.addEdge(2, 3, 10);
    g.addEdge(2, 6, 6);
    g.addEdge(3, 4, 3);
    g.addEdge(3, 6, 12);
    g.addEdge(3, 7, 1);
    g.addEdge(4, 7, 5);
    g.addEdge(4, 8, 20);
    g.addEdge(5, 6, 25);
    g.addEdge(6, 7, 11);
    g.addEdge(7, 8, 15);

	g.toString();
    cout << endl;
    cout <<"The cost of the edge at (2,3): " <<g.adjMatrix[2][3];
    cout<<endl;
    cout << "BFS traversal starting from vertex 1: ";
    g.bfs(1);
    cout << endl;


    vector<Edge> edges = {
        {1, 2, 2},
        {1, 5, 22},
        {1, 6, 8},
        {2, 1, 2},
        {2, 6, 6},
        {2, 3, 10},
        {3, 2, 10},
        {3, 6, 12},
        {3, 7, 1},
        {3, 4, 3},
        {4, 3, 3},
        {4, 7, 5},
        {4, 8, 20},
        {5, 1, 22},
        {5, 6, 25},
        {6, 5, 25},
        {6, 1, 8},
        {6, 2, 6},
        {6, 3, 12},
        {6, 7, 11},
        {7, 6, 11},
        {7, 3, 1},
        {7, 4, 5},
        {7, 8, 15},
        {8, 7, 15},
        {8, 4, 20}
    };

    int n = 8; // Number of vertices

    minimumSpanningTree(edges, n);

    return 0;

}
