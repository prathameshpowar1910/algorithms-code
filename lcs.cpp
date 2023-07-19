#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int x,int y) {
    int arr[x+1][y+1];

    for (int i=0;i< x+1;i++) {
        for (int j = 0; j<y+1;j++){
            if (i==0 || j==0) {
                arr[i][j] =0;
            } else if (s1[i-1]== s2[j-1]) {
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else {
                arr[i][j] = max(arr[i][j-1],arr[i-1][j]);
            }
        }
    }

    return arr[x][y];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int x = s1.size();
    int y = s2.size();
    int res =  lcs(s1, s2,x,y);
    cout << "Longest Common Subsequence: " << res << endl;

    return 0;
}
