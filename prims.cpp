#include<bits/stdc++.h>
using namespace std;

// Structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    int weight;
    AdjListNode* next;
};

// Structure to represent an adjacency list
struct AdjList {
    AdjListNode* head;
};

// Structure to represent a graph
struct Graph {
    int V;
    AdjList* array;
};

// Function prototypes
void primMST(Graph* graph);

// Function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* newNode = new AdjListNode;
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = nullptr;
    return newNode;
}

// Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->array = new AdjList[V];  // Allocate an array of AdjLists

    for (int i = 0; i < V; ++i)
        graph->array[i].head = nullptr;  // Initialize each list head as nullptr

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    // Add edge from src to dest
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add edge from dest to src
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Prim's algorithm to find MST
// Prim's algorithm to find MST and calculate total minimum weight
// Prim's algorithm to find MST and calculate total minimum weight
void primMST(Graph* graph) {
    int V = graph->V;

    // Arrays for MST construction
    int* parent = new int[V];
    int* key = new int[V];
    bool* inMST = new bool[V];

    // Initialize all keys to INT_MAX except the first vertex, which is set to 0
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;  // Start with the first vertex
    parent[0] = -1;  // First vertex is the root of the MST

    int totalMinWeight = 0; // Accumulate the total minimum weight of the MST

    // Iterate through all vertices
    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum key value that is not in MST
        int minKey = INT_MAX;
        int minIndex = -1;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Add the chosen vertex to the MST
        inMST[minIndex] = true;

        // Update the total minimum weight by adding the chosen key value

            totalMinWeight += key[minIndex];


        // Update the key and parent of adjacent vertices of the chosen vertex
        AdjListNode* pCrawl = graph->array[minIndex].head;
        while (pCrawl) {
            int v = pCrawl->dest;
            if (!inMST[v] && pCrawl->weight < key[v]) {
                parent[v] = minIndex;
                key[v] = pCrawl->weight;
            }
            pCrawl = pCrawl->next;
        }
    }

    // Display the constructed MST
    cout << "Minimum Spanning Tree (MST):\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " -- " << i << "\tWeight: " << key[i] << endl;
    }

    // Display the total minimum weight of the MST
    cout << "Total minimum weight of MST: " << totalMinWeight << endl;

    // Clean up allocated memory
    delete[] parent;
    delete[] key;
    delete[] inMST;
}


// Main function
int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph* graph = createGraph(V);

    // Input the edges of the graph
    cout << "Enter edges and weights (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        addEdge(graph, src, dest, weight);
    }

    // Find MST using Prim's algorithm
    primMST(graph);

    // Free graph memory
    for (int i = 0; i < V; i++) {
        AdjListNode* current = graph->array[i].head;
        while (current) {
            AdjListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }

    delete[] graph->array;
    delete graph;

    return 0;
}
