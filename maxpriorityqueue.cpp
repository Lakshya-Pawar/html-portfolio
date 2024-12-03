#include <iostream>
#include <queue>
#include<ctime>
using namespace std;

void priorityQueueSortMax(int arr[], int n) {
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    for (int i = n - 1; i >= 0; i--) {
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
    int arr[] = {15, 3, 17, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    cout<<endl<<"quick sort: ";
    clock_t time_req = clock();
    priorityQueueSortMax(arr, n);
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

    cout << "Sorted array (Max Priority Queue): ";
    printArray(arr, n);

    return 0;
}

