#include<iostream>
#include<ctime>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Node {
    int level, profit, weight;
    float bound;
};

float bound(Node u, int n, int W, vector<int>& values, vector<int>& weights) {
    if (u.weight >= W)
        return 0;
    int profit_bound = u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;

    while (j < n && total_weight + weights[j] <= W) {
        total_weight += weights[j];
        profit_bound += values[j];
        j++;
    }
    if (j < n)
        profit_bound += (W - total_weight) * values[j] / (float)weights[j];

    return profit_bound;
}

void knapsack(int W, vector<int>& values, vector<int>& weights, int n) {
    queue<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = 0.0;
    Q.push(u);

    int maxProfit = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u.level == -1)
            v.level = 0;
        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;
        v.weight = u.weight + weights[v.level];
        v.profit = u.profit + values[v.level];

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, values, weights);
        if (v.bound > maxProfit)
            Q.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, values, weights);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    cout << "Maximum profit: " << maxProfit << endl;
}

int main() {
    int W = 50;
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int n = values.size();

    clock_t time_req = clock();
    knapsack(W, values, weights, n);
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}
