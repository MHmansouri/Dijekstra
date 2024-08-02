#include <iostream> // Input and output stream library for user interaction
#include <vector>   // Container library for dynamic arrays (vectors)
#include <queue>    // Priority queue library for Dijkstra's algorithm
#include <limits>   // Library providing constants for numeric limits

using namespace std;

const int INF = numeric_limits<int>::max(); // Define infinity as maximum integer value

class Graph {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list to store edges and weights

    explicit Graph(int vertices) : V(vertices), adj(vertices) {} // Constructor for the graph

    // Add an edge between vertices u and v with weight w
    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w); // Add v with weight w to u's adjacency list
        adj[v].emplace_back(u, w); // Add u with weight w to v's adjacency list
    }

    // Dijkstra's algorithm implementation:
    vector<int> dijkstra(int src) {
        vector<int> distance(V, INF); // Initialize distances to infinity
        distance[src] = 0;  // Distance from source to itself is 0

        // Priority queue to store vertices based on their distance
        // The priority queue holds pairs of integers (distance, vertex), where 'distance' is the shortest distance from the source,
        // and 'vertex' is the vertex ID.
        // 'greater<>' is a comparison function that ensures the elements with smaller 'distance' values are considered higher priority.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, src); // Enqueue source with distance 0

        while (!pq.empty()) {
            int u = pq.top().second; // Get the vertex with the smallest distance
            int dist = pq.top().first; // Get the current distance
            pq.pop(); // Dequeue the vertex

            // If the stored distance is smaller than the calculated distance, skip
            if (dist > distance[u]) continue;

            // Explore neighbors of the current vertex
            for (const auto &neighbor: adj[u]) {
                int v = neighbor.first; // Neighbor's vertex
                int weight = neighbor.second; // Weight of edge to neighbor

                // If a shorter path is found to neighbor, update distance and enqueue
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight; // Update shortest distance
                    pq.emplace(distance[v], v); // Enqueue neighbor with new distance
                }
            }
        }

        return distance; // Return shortest distances from the source
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "\nEnter the number of edges: ";
    cin >> E;

    Graph graph(V);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cout << "\nEnter edge " << i + 1 << " (source, destination, weight):\n";
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int src;
    cout << "\nEnter the source vertex: ";
    cin >> src;

    vector<int> distances = graph.dijkstra(src);

    cout << "\nShortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To vertex " << i + 1 << ": " << distances[i] << endl;
    }

    return 0;
}