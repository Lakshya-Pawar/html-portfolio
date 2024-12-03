#include <iostream>
#include<ctime>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, vector<int>& color, int m, int v) {
    if (v == graph.size())
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, color, m, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> color(graph.size(), 0);
    return graphColoringUtil(graph, color, m, 0);
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; 

    clock_t time_req = clock();
    if (graphColoring(graph, m))
        cout << "Solution exists with " << m << " colors." << endl;
    else
        cout << "No solution exists with " << m << " colors." << endl;
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
