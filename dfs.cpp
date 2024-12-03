#include <iostream>
#include<ctime>
using namespace std;

void DFSUtil(int graph[5][5], int node, bool visited[], int n) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited, n);
        }
    }
}

void DFS(int graph[5][5], int start, int n) {
    bool visited[5] = {false};

    cout << "DFS Traversal: ";
    DFSUtil(graph, start, visited, n);
    cout << endl;
}

int main() {
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    cout<<endl<<"quick sort: ";
    clock_t time_req = clock();
    DFS(graph, 0, 5);
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
