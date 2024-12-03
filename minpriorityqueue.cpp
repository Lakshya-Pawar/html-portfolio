#include <iostream>
#include<ctime>
#include <queue>
using namespace std;

void priorityQueueSortMin(int arr[], int n) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    for (int i = 0; i < n; i++) {
        arr[i] = pq.top();
        pq.pop();
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {20, 5, 15, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    cout<<endl<<"quick sort: ";
    clock_t time_req = clock();
    priorityQueueSortMin(arr, n);
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

    cout << "Sorted array (Min Priority Queue): ";
    printArray(arr, n);

    return 0;
}
