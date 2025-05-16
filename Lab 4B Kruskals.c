#include <stdio.h>
#include <stdlib.h>

int comparator(const void *a, const void *b) {
    int *p1 = (int *)a;
    int *p2 = (int *)b;
    return p1[2] - p2[2];
}

void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[], int n) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskalAlgo(int n, int edge[n][3]) {
    qsort(edge, n, sizeof(edge[0]), comparator);
    int parent[n], rank[n];
    makeSet(parent, rank, n);
    int minCost = 0;
    for (int i = 0; i < n; i++) {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];
        if (v1 != v2) {
            unionSet(v1, v2, parent, rank, n);
            minCost += wt;
            printf("Edge %d - %d included with weight %d\n", edge[i][0], edge[i][1], wt);
        }
    }
    return minCost;
}

int main() {
    int edge[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    printf("Minimum cost of MST: %d\n", kruskalAlgo(5, edge));
    return 0;
}

OUTPUT:
Edge 2 - 3 included with weight 4
Edge 0 - 3 included with weight 5
Edge 0 - 1 included with weight 10
Minimum cost of MST: 19
