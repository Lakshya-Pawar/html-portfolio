#include <iostream>
#include<ctime>
using namespace std;

void findMaxMin(int arr[], int low, int high, int &min, int &max) {
    if (low == high) {
        if (arr[low] > max) {
            max = arr[low];
        }
        if (arr[low] < min) {
            min = arr[low];
        }
        return;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            if (arr[low] > max) {
                max = arr[low];
            }
            if (arr[high] < min) {
                min = arr[high];
            }
        } else {
            if (arr[high] > max) {
                max = arr[high];
            }
            if (arr[low] < min) {
                min = arr[low];
            }
        }
        return;
    }
    int mid = (low + high) / 2;
    findMaxMin(arr, low, mid, min, max);
    findMaxMin(arr, mid + 1, high, min, max);
}

int main() {
    int n;
    cin>>n;
    int size = n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int min = arr[0], max = arr[0];

    clock_t time_req = clock();
    findMaxMin(arr, 0, size - 1, min, max);
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}
