#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
    int visited[MAX];
};

// Create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// ================= BFS =================
void BFS(struct Graph* graph, int startVertex) {
    int queue[MAX], front = 0, rear = 0;
    for(int i=0; i<graph->numVertices; i++)
        graph->visited[i] = 0;

    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS: ");
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// ================= DFS =================
void DFSUtil(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex])
            DFSUtil(graph, adjVertex);
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    for(int i=0; i<graph->numVertices; i++)
        graph->visited[i] = 0;

    printf("DFS: ");
    DFSUtil(graph, startVertex);
    printf("\n");
}

// ================= PRINT GRAPH =================
void printGraph(struct Graph* graph) {
    for(int v=0; v<graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("%d: ", v);
        while(temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// ================= MAIN =================
int main() {
    int vertices, edges, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i=0; i<edges; i++) {
        printf("Enter edge %d (src dest): ", i+1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nAdjacency List:\n");
    printGraph(graph);

    printf("\nEnter starting vertex for BFS and DFS: ");
    scanf("%d", &start);

    BFS(graph, start);
    DFS(graph, start);

    return 0;
}
