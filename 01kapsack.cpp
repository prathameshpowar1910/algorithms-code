#include <iostream>
#include <algorithm>

using namespace std;

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n+1][capacity+1];
    for (int i = 0; i < n+1; i++) {
        for (int w = 0; w < capacity+1; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i-1] <= w) {
                 dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][capacity];
}



int main() {
    int capacity = 50;
    int weights[] = {40, 45, 5};
    int values[] = {50, 100, 220};
    int n = sizeof(weights) / sizeof(weights[0]);
    int totalValue = knapsack(capacity, weights, values, n);
    cout << "Maximum value: " << totalValue << endl;
    return 0;
}
