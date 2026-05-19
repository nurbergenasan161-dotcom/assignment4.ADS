#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Graph {
private:
    map<char, vector<char>> adj;

public:

    void add_edge(char u, char v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS
    void dfs_helper(char node, map<char, bool>& visited) {

        visited[node] = true;

        cout << node << " ";

        for (char neighbor : adj[node]) {

            if (!visited[neighbor]) {
                dfs_helper(neighbor, visited);
            }
        }
    }

    void DFS(char start) {

        map<char, bool> visited;

        cout << "DFS Traversal: ";

        dfs_helper(start, visited);

        cout << endl;
    }

    // BFS
    void BFS(char start) {

        map<char, bool> visited;

        queue<char> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {

            char current = q.front();
            q.pop();

            cout << current << " ";

            for (char neighbor : adj[current]) {

                if (!visited[neighbor]) {

                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {

    Graph g;

    // Add edges
    g.add_edge('A', 'B');
    g.add_edge('A', 'D');
    g.add_edge('B', 'C');
    g.add_edge('B', 'D');
    g.add_edge('B', 'E');
    g.add_edge('B', 'F');
    g.add_edge('D', 'F');

    cout << "Starting Node: F\n\n";

    g.DFS('F');
    g.BFS('F');

    return 0;
}
