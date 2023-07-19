//Fractional Knapsack
#include <bits/stdc++.h>
using namespace std;

struct Item {
    char id;
    int weight,value;
};

bool compareItems(Item a, Item b) {
    return ((double)a.value / a.weight) > ((double)b.value / b.weight);
}

int knapsack(int capacity, Item items[], int n) {
    sort(items,items+n,compareItems);

    int currentWeight = 0, totalValue = 0;
    char itemsList[n];
    int count =0 ;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            itemsList[i] = items[i].id;
            count++;
        }
        else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)remainingCapacity / items[i].weight * items[i].value;
            itemsList[i] = items[i].id;
            count++;
            break;
        }
    }
    for (int i = 0 ; i<count;i++) {
        cout<<itemsList[i]<<" ";
    }
    cout<<endl;
    return totalValue;
}

int main() {
    int capacity = 50;
    Item items[] = {{'a',10, 60}, {'b',20, 100}, {'c',40, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    int totalValue = knapsack(capacity, items, n);
    cout << "Maximum value: " << totalValue << endl;
    return 0;
}
