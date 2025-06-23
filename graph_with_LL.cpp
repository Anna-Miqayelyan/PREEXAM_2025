#include <iostream>
using namespace std;

// Linked list node to store neighbors
struct Node {
    int dest;       // destination vertex
    Node* next;     // pointer to next neighbor
};

// Graph structure
struct Graph {
    int V;          // Number of vertices
    Node** adjList; // Array of linked lists

    // Constructor
    Graph(int v) {
        V = v;
        adjList = new Node*[V];
        for (int i = 0; i < V; ++i)
            adjList[i] = nullptr;
    }

    // Add edge (u <-> v)
    void addEdge(int u, int v) {
        // Add v to u's list
        Node* newNode = new Node{v, adjList[u]};
        adjList[u] = newNode;

        // Add u to v's list (since undirected)
        newNode = new Node{u, adjList[v]};
        adjList[v] = newNode;
    }

    // Print graph
    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ":";
            Node* temp = adjList[i];
            while (temp != nullptr) {
                cout << " -> " << temp->dest;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < V; ++i) {
            Node* current = adjList[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjList;
    }
};

// Main
int main() {
    Graph g(5); // create graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
