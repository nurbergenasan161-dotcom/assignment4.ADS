#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

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
        adj[v].push_back({u, weight}); // undirected graph
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

    // DFS
    void DFS(char start) {
        map<char, bool> visited;

        cout << "\nDFS Traversal: ";
        dfs_helper(start, visited);
        cout << endl;
    }

    void dfs_helper(char node, map<char, bool>& visited) {
        visited[node] = true;

        cout << node << " ";

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor.first]) {
                dfs_helper(neighbor.first, visited);
            }
        }
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

            for (auto neighbor : adj[current]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }

        cout << endl;
    }

    // Dijkstra
    void dijkstra(char start) {

        map<char, int> dist;
        map<char, char> parent;

        for (auto x : adj) {
            dist[x.first] = INT_MAX;
        }

        dist[start] = 0;

        priority_queue<
            pair<int, char>,
            vector<pair<int, char>>,
            greater<pair<int, char>>
        > pq;

        pq.push({0, start});

        while (!pq.empty()) {

            int currentDist = pq.top().first;
            char currentNode = pq.top().second;

            pq.pop();

            for (auto neighbor : adj[currentNode]) {

                char nextNode = neighbor.first;
                int weight = neighbor.second;

                if (dist[currentNode] + weight < dist[nextNode]) {

                    dist[nextNode] = dist[currentNode] + weight;
                    parent[nextNode] = currentNode;

                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        cout << "\nShortest Paths from " << start << ":\n";

        for (auto x : dist) {

            cout << start << " -> " << x.first;

            if (x.second == INT_MAX) {
                cout << " = No Path\n";
            }
            else {
                cout << " = " << x.second << " | Path: ";

                vector<char> path;
                char temp = x.first;

                path.push_back(temp);

                while (temp != start) {
                    temp = parent[temp];
                    path.push_back(temp);
                }

                for (int i = path.size() - 1; i >= 0; i--) {
                    cout << path[i];

                    if (i != 0) {
                        cout << " -> ";
                    }
                }

                cout << endl;
            }
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

    // Task 1
    g.print_graph();

    // Task 2
    cout << "\nStarting Node for DFS and BFS: F\n";
    g.DFS('F');
    g.BFS('F');

    // Task 3
    g.dijkstra('A');

    return 0;
}
