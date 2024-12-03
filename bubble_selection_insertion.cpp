#include<iostream>
#include<ctime>
using namespace std;

void bubblesort(int n, int arr[]){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection(int n, int arr[]){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void insertion(int n, int arr[]){
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"bubble sort: "<<endl;
    clock_t time_req = clock();
    bubblesort(n, arr);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    time_req = clock() - time_req;
    cout << endl << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

    cout<<"selection sort: "<<endl;
    clock_t time_req2 = clock();
    selection(n, arr);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    time_req2 = clock() - time_req2;
    cout << endl << (float)time_req2 / CLOCKS_PER_SEC << " seconds" << endl;

    cout<<"insertion sort: "<<endl;
    clock_t time_req3 = clock();
    insertion(n, arr); 
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    time_req3 = clock() - time_req3;
    cout << endl << (float)time_req3 / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}