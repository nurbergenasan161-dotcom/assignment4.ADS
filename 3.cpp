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

    void add_edge(char u, char v, int weight) {

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

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

            char current = pq.top().second;
            pq.pop();

            for (auto neighbor : adj[current]) {

                char next = neighbor.first;
                int weight = neighbor.second;

                if (dist[current] + weight < dist[next]) {

                    dist[next] = dist[current] + weight;
                    parent[next] = current;

                    pq.push({dist[next], next});
                }
            }
        }

        cout << "Shortest Paths from A:\n";

        for (auto x : dist) {

            cout << "A -> " << x.first;

            if (x.second == INT_MAX) {
                cout << " = No Path\n";
            }
            else {

                cout << " = " << x.second << " | Path: ";

                vector<char> path;

                char temp = x.first;

                while (temp != start) {
                    path.push_back(temp);
                    temp = parent[temp];
                }

                path.push_back(start);

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

    g.add_edge('B', 'A', 4);
    g.add_edge('C', 'B', 8);
    g.add_edge('D', 'B', 8);
    g.add_edge('E', 'B', 1);
    g.add_edge('F', 'D', 10);
    g.add_edge('A', 'D', 6);
    g.add_edge('F', 'B', 1);

    g.dijkstra('A');

    return 0;
}
