# Dijkstra's Algorithm Project

## About the Project

This repository contains the implementation of Dijkstra's algorithm, developed as part of a university project. Dijkstra's algorithm is used to find the shortest paths from a single source vertex to all other vertices in a weighted graph with non-negative weights.

### Features

- **Single Source Shortest Path:** Computes the shortest paths from a given source vertex to all other vertices.
- **Efficient Priority Queue:** Utilizes a priority queue to efficiently select the next vertex to process.
- **Non-Negative Weights:** Handles graphs with non-negative weight edges.

### Implementation Details

The project is implemented in C++. The main components of the code include:

- **Graph Class:** Represents the graph using an adjacency list and includes methods to add edges.
- **Dijkstra Function:** Implements Dijkstra's algorithm using a priority queue to find the shortest paths.

### Example Usage

1. **Input:**
    ```
    Enter the number of vertices: 5
    Enter the number of edges: 8
    Enter edge 1 (source, destination, weight): 0 1 6
    Enter edge 2 (source, destination, weight): 0 2 7
    Enter edge 3 (source, destination, weight): 1 2 8
    Enter edge 4 (source, destination, weight): 1 3 5
    Enter edge 5 (source, destination, weight): 1 4 7
    Enter edge 6 (source, destination, weight): 2 3 4
    Enter edge 7 (source, destination, weight): 2 4 2
    Enter edge 8 (source, destination, weight): 3 4 3
    Enter the source vertex: 0
    ```

2. **Output:**
    ```
    Shortest distances from vertex 0:
    To vertex 1: 6
    To vertex 2: 7
    To vertex 3: 11
    To vertex 4: 9
    ```

### Contributing

Contributions are welcome! If you have suggestions, improvements, or bug fixes, please fork the repository and submit a pull request.

### License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
