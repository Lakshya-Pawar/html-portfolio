#include<iostream>
#include<ctime>
using namespace std;

int linearsearch(int n, int arr[], int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return 1; 
        }
    }
    return 0;
}

int binarysearch(int n, int arr[], int key) {
    int s = 0;
    int e = n;
    for (int i = 0; i < n; i++) {
        int mid = (s + e) / 2;
        if (arr[mid] == key) {
            return 1;
        } else if (key < arr[mid]) {
            e = mid - 1;
        } else if (key > arr[mid]) {
            s = mid + 1;
        }
    }
    return 0;
}

int recursiveBinarySearch(int n, int arr[], int s, int e, int key) {
    if(s > e) {
        return 0;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key) {
        return 1;
    } else if (key < arr[mid]) {
        return recursiveBinarySearch(n, arr, s, mid-1, key);
    } else if (key > arr[mid]) { 
        return recursiveBinarySearch(n, arr, mid+1, e, key);
    }
    return 0;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << endl;
    int key;
    cin >> key;

    clock_t time_req;
    time_req = clock();
    int check = linearsearch(n, arr, key);
    if (check == 1) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
    time_req = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

    clock_t time_req2;
    time_req2 = clock();
    int check2 = binarysearch(n, arr, key);
    if (check2 == 1) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
    time_req2 = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req2 / CLOCKS_PER_SEC << " seconds" << endl;

    clock_t time_req3;
    time_req3 = clock();
    int s = 0;
    int e = n;
    int check3 = recursiveBinarySearch(n, arr, s, e, key);
    if (check3 == 1) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
    time_req3 = clock() - time_req;
    cout << endl << "Execution Time: " << (float)time_req3 / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}