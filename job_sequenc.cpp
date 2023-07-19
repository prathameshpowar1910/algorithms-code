#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
    char id;
    int profit,deadline;
};

bool sortByProfit(Job a,Job b) {
    return a.profit > b.profit;
}

void jobSequencing(Job jobs[], int n) {
    sort(jobs, jobs + n, sortByProfit);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
       maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    int schedule[maxDeadline+1] = {0};
    int totalProfit = 0;
    int jobsDone = 0;
    char jobsList[maxDeadline+1];

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j >= 1; j--) {
            if (schedule[j] == 0) {
                schedule[j] = 1;
                totalProfit += jobs[i].profit;
                jobsDone++;
                jobsList[j] = jobs[i].id;
                break;
            }
        }
        if (jobsDone == maxDeadline) {
            break;
        }
    }
    for (int i = 1; i <= maxDeadline; i++ ) {
        cout<<jobsList[i]<<" ";
    }
    cout <<endl<< "Maximum Profit: " << totalProfit << endl;
}

int main() {
    Job jobs[] = {{'A',350,4},{'B',250,2},{'C',450,4},{'D',300,1},{'E',150,5},{'F',400,3},{'G',100,3}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobSequencing(jobs, n);
    return 0;
}
