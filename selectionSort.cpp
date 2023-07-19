#include <bits/stdc++.h>
using namespace std;
int main() {

    int arr[] = {4,3,6,2,1};
    int n =5;
    for (int i =0 ; i<n-1 ; i++) {
        int minVal = i;
        for (int j = i+1;j<n;j++) {
            if (arr[j]<arr[minVal]) {
                minVal = j;
            }
        }
        if (minVal!=i) {
            swap(arr[minVal],arr[i]);
        }
    }
       for (int i = 0 ; i<n ; i++) {
        cout<<arr[i]<<" ";
    }

}
