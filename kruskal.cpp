#include <iostream>
#include<ctime>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (xroot != yroot) {
        parent[xroot] = yroot;
    }
}

void kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> mst;
    for (Edge e : edges) {
        int x = find(parent, e.src);
        int y = find(parent, e.dest);
        if (x != y) {
            mst.push_back(e);
            Union(parent, x, y);
        }
    }

    cout << "Edge \tWeight\n";
    for (Edge e : mst) {
        cout << e.src << " - " << e.dest << "\t" << e.weight << "\n";
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    clock_t time_req = clock();
    kruskal(V, edges);
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}
