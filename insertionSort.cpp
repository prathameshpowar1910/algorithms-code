#include <bits/stdc++.h>
using namespace std;
int main() {

    int arr[] = {4,3,6,2,1};
    int n = 5;
    for (int i = 1 ; i<n ; i++) {
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        j--;
    }

    for (int i = 0 ; i<n ; i++) {
        cout<<arr[i]<<" ";
    }

}
