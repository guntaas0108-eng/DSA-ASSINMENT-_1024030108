#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm> 
#include <limits>
#include <tuple> 
#include <numeric> 
#define INT_MAX 
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }


    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

// Define the Graph class
class Graph {
private:
    int V; 
    vector<vector<pair<int, int>>> adj;
    vector<tuple<int, int, int>> edges;

public:
 
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

 
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
        edges.push_back({w, u, v}); 
    }

    // --- 1. Breadth First Search (BFS) ---
    void BFS(int startNode) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

       
            for (auto& edge : adj[u]) {
                int v = edge.first; 
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    // --- 2. Depth First Search (DFS) ---
private:

    void DFS_util(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";


        for (auto& edge : adj[u]) {
            int v = edge.first;
            if (!visited[v]) {
                DFS_util(v, visited);
            }
        }
    }

public:

    void DFS(int startNode) {
        vector<bool> visited(V, false);
        DFS_util(startNode, visited);
        cout << endl;
    }

    // --- 3a. Minimum Spanning Tree (Kruskal's Algorithm) ---
    void kruskalMST() {

        sort(edges.begin(), edges.end());

        DSU dsu(V);
        int mst_weight = 0;

        cout << "Edges in Kruskal's MST:" << endl;
        for (auto& edge : edges) {
            int w = get<0>(edge);
            int u = get<1>(edge);
            int v = get<2>(edge);

            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                mst_weight += w;
                cout << "  " << u << " - " << v << " (weight " << w << ")" << endl;
            }
        }
        cout << "Total MST Weight: " << mst_weight << endl;
    }

    // --- 3b. Minimum Spanning Tree (Prim's Algorithm) ---
    void primMST(int startNode = 0) {
       
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> key(V, INT_MAX);    
        vector<int> parent(V, -1);  
        vector<bool> inMST(V, false); 

        pq.push({0, startNode});
        key[startNode] = 0;

        int mst_weight = 0;

        cout << "Edges in Prim's MST (from node " << startNode << "):" << endl;
        while (!pq.empty()) {
            int u = pq.top().second;
            int w = pq.top().first; 
            pq.pop();


            if (inMST[u]) continue; 

            inMST[u] = true;
            mst_weight += w;

            if (parent[u] != -1) {
                cout << "  " << parent[u] << " - " << u << " (weight " << w << ")" << endl;
            }

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

           
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }
        cout << "Total MST Weight: " << mst_weight << endl;
    }

    void dijkstra(int startNode) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


        vector<int> dist(V, INT_MAX);

        pq.push({0, startNode});
        dist[startNode] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;  
            int u = pq.top().second; 
            pq.pop();
            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra's Shortest Distances from node " << startNode << ":" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "  Node " << i << ": ";
            if (dist[i] == INT_MAX) {
                cout << "INF" << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }
};

int main() {

    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(4, 5, 10);
    
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    

    // --- 1. BFS ---
    cout << "--- Breadth First Search (BFS) ---" << endl;
    cout << "BFS starting from node 0: ";
    g.BFS(0);
    cout << "-----------------------------------" << endl << endl;

    // --- 2. DFS ---
    cout << "--- Depth First Search (DFS) ---" << endl;
    cout << "DFS starting from node 0: ";
    g.DFS(0);
    cout << "---------------------------------" << endl << endl;

    // --- 3a. Kruskal's MST ---
    cout << "--- Kruskal's MST ---" << endl;
    g.kruskalMST();
    cout << "------------------------" << endl << endl;

    // --- 3b. Prim's MST ---
    cout << "--- Prim's MST ---" << endl;
    g.primMST(0);
    cout << "---------------------" << endl << endl;

    // --- 4. Dijkstra's Algorithm ---
    cout << "--- Dijkstra's Shortest Path ---" << endl;
    g.dijkstra(0); 
    cout << "---------------------------------" << endl << endl;

    return 0;
}