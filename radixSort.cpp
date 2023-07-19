#include<bits/stdc++.h>
using namespace std;

void countingSort(int *a,int n,int div){
    int count[10]={0};

    for(int i=0;i<n;i++)
        ++count[(a[i]/div)%10];

    for(int i=1;i<10;i++)
        count[i]+=count[i-1];

    int temp[n];

    for(int i=n-1;i>=0;i--){
        temp[--count[(a[i]/div)%10]]=a[i];
    }

    // Updating the elements in array.
    for(int i=0;i<n;i++)
        a[i]=temp[i];
}

// Radix Sort function
void radixSort(int a[], int n){
    // Finding the maximum element
    // of the array.
    int max=0;
    for(int i=0;i<n;i++)
        if(a[i]>max)
            max=a[i];

    // For each digit in max, calling
    // the countingSort for ith digit.
    for(int div=1 ; max/div>0 ; div*=10 ){
        countingSort(a,n,div);
    }
}

// Main function
int main(){
    // Initializing the array.
    int a[]={1,1,4,2,12,6,1,9,21};
    int n=9;
    // Applying the Radix sort function.
    radixSort(a,n);

    // Printing the array.
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
