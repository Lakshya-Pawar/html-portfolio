#include <iostream>
#include<ctime>
using namespace std;

void minHeapify(int arr[], int n, int i) {
    int smallest = i;        
    int left = 2 * i + 1;     
    int right = 2 * i + 2;  

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        minHeapify(arr, n, smallest);
    }
}

void heapSortMin(int arr[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    cout<<endl<<"quick sort: ";
    clock_t time_req = clock();
    heapSortMin(arr, n);
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

    cout << "Sorted array (Min Heap Sort): ";
    printArray(arr, n);

    return 0;
}