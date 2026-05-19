#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph {
private:
    map<char, vector<pair<char, int>>> adj;

public:

    // Add vertex
    void add_vertex(char v) {
        adj[v];
    }

    // Add edge
    void add_edge(char u, char v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // Print adjacency list
    void print_graph() {

        cout << "Adjacency List:\n";

        for (auto x : adj) {

            cout << x.first << " -> ";

            for (auto y : x.second) {
                cout << "(" << y.first << ", " << y.second << ") ";
            }

            cout << endl;
        }
    }
};

int main() {

    Graph g;

    // Add vertices
    g.add_vertex('A');
    g.add_vertex('B');
    g.add_vertex('C');
    g.add_vertex('D');
    g.add_vertex('E');
    g.add_vertex('F');

    // Add edges
    g.add_edge('B', 'A', 4);
    g.add_edge('C', 'B', 8);
    g.add_edge('D', 'B', 8);
    g.add_edge('E', 'B', 1);
    g.add_edge('F', 'D', 10);
    g.add_edge('A', 'D', 6);
    g.add_edge('F', 'B', 1);

    g.print_graph();

    return 0;
}
