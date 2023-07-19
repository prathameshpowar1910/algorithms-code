#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;

int arr[MAXN], n, sum;
vector<int> subset;

void printSubset() {
    cout << "Subset found: ";
    for(int i=0; i<subset.size(); i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void findSubset(int idx, int currentSum) {
    if(currentSum == sum) {
        printSubset();
        return;
    }
    if(idx == n) {
        return;
    }
    if(currentSum > sum) {
        return;
    }
    // include the current element in the subset
    subset.push_back(arr[idx]);
    findSubset(idx+1, currentSum+arr[idx]);
    subset.pop_back(); // backtrack
    // exclude the current element from the subset
    findSubset(idx+1, currentSum);
}

int main() {
    cout << "Enter the number of elements in the set: ";
    cin >> n;
    cout << "Enter the elements of the set: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the required sum: ";
    cin >> sum;
    findSubset(0, 0);
    return 0;
}
