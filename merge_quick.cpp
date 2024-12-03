#include <iostream>
#include<ctime>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;  
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  

        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}

void merge(int arr[], int l, int mid, int r) {
    int arr_1 = mid - l + 1, arr_2 = r - mid;
    int L[arr_1], R[arr_2];

    for (int i = 0; i < arr_1; i++) L[i] = arr[l + i];
    for (int i = 0; i < arr_2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l; 
    while (i < arr_1 && j < arr_2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < arr_1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < arr_2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
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

    cout<<endl<<"quick sort: ";
    clock_t time_req = clock();
    quickSort(arr, 0, size - 1);
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
    printArray(arr, size);

    cout<<endl<<"merge sort: ";
    clock_t time_req2 = clock();
    mergeSort(arr, 0, size - 1);
    time_req2 = clock() - time_req2;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
    printArray(arr, size);

    return 0;
}