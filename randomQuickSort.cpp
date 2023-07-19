#include<bits/stdc++.h>
using namespace std;

// Partition function to divide the array into smaller sub-arrays
int partition(int arr[], int low, int high){
    int pivot = arr[high];   // Select the last element as pivot
    int i = low - 1;         // Index of smaller element

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){ // If current element is smaller than or equal to pivot
            i++;            // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

int randomizedPartition(int arr[], int low, int high) {
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}
// Quick Sort function to sort the array
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivotIndex = randomizedPartition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main(){
    int arr[] = {3, 5, 4, 2, 6, 7, 1, 8,2,4,10,2,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout<<"Sorted array: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


