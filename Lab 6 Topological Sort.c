#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int u = temp->vertex;
        if (!visited[u]) {
            dfs(u, adj, visited);
        }
        temp = temp->next;
    }

    push(v); 
}

int main() {
    int vertices, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Node* adj[MAX];
    int visited[MAX];
	int i;
    for (i = 0; i < vertices; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    for (i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
        }
    }

    printf("Topological Sort (using DFS): ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}
