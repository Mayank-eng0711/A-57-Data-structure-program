#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
};

// Stack for topological order
struct Stack {
    int items[MAX];
    int top;
};

// ================= Stack functions =================
void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    s->items[++s->top] = value;
}

int pop(struct Stack* s) {
    if (!isEmpty(s))
        return s->items[s->top--];
    return -1;
}

// ================= Graph functions =================
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// ================= DFS for Topological Sort =================
void topologicalSortUtil(struct Graph* graph, int v, int visited[], struct Stack* stack) {
    visited[v] = 1;

    struct Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int adj = temp->vertex;
        if (!visited[adj])
            topologicalSortUtil(graph, adj, visited, stack);
        temp = temp->next;
    }

    push(stack, v);
}

void topologicalSort(struct Graph* graph) {
    int visited[MAX] = {0};
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; i < graph->numVertices; i++)
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, &stack);

    printf("Topological Sort: ");
    while (!isEmpty(&stack))
        printf("%d ", pop(&stack));
    printf("\n");
}

// ================= MAIN =================
int main() {
    int vertices, edges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    topologicalSort(graph);

    return 0;
}
