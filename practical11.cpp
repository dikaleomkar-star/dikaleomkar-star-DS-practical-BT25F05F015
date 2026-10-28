
#include <iostream>
#include <queue>
using namespace std;

int graph[100][100];
bool visited[100];
int n;

void BFS(int start) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int edges, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid number of vertices.";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    if (edges < 0 || edges > n * (n - 1) / 2) {
        cout << "Invalid number of edges.";
        return 0;
    }

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;

        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid edge.";
            return 0;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= n) {
        cout << "Invalid starting vertex.";
        return 0;
    }

    cout << "BFS Traversal: ";
    BFS(start);

    cout << endl;
    return 0;
}
