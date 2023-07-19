#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int n) {
    // create an auxiliary stack
    stack<int> s;

    // push initial values of l and h to the stack
    s.push(0);
    s.push(n - 1);

    while (!s.empty()) {
        // pop h and l
        int h = s.top();
        s.pop();
        int l = s.top();
        s.pop();

        int pivot = partition(arr, l, h);

        // if there are elements on the left side of pivot, push them to the stack
        if (pivot - 1 > l) {
            s.push(l);
            s.push(pivot - 1);
        }

        // if there are elements on the right side of pivot, push them to the stack
        if (pivot + 1 < h) {
            s.push(pivot + 1);
            s.push(h);
        }
    }
}

int main() {
    int arr[] = {3, 5, 4, 2, 6, 7, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr,n);
    cout<<"Sorted array: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
