#include <bits/stdc++.h>
using namespace std;
int main() {

    int arr[] = {4,3,6,2,1};
    int n =5;
    int k = *max_element(arr,arr+n);

    int counts[k+1] = {0};
    int b[n];

    for (int i = 0 ; i<n  ;i++) {
        ++counts[arr[i]];
    }

    for (int i = 1 ; i<k+1 ; i++) {
        counts[i] = counts[i] + counts[i-1];
    }

    for (int i = n-1 ; i>=0 ; i--) {
        b[--counts[arr[i]]] = arr[i];
    }
    for(int i=0;i<n;i++)
        arr[i]=b[i];
    for (int i = 0 ; i<n ; i++) {
        cout<<arr[i]<<" ";
    }
}
