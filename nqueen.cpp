#include <bits/stdc++.h>
using namespace std;

const int N = 4;
int board[N][N] = {0};
int counts = 1;

void printBoard() {
    cout<<"Solution " << counts << endl;
    for (int i = 0 ; i<N ; i++) {
        for (int j = 0 ; j<N ; j++) {
            if (board[i][j]) {
                cout<<"Q ";
            } else {
                cout<<"_ ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

bool canPlaceQueen(int row,int col) {

    for (int j=0 ; j<col ; j++) {
        if(board[row][j]) {
            return false;
        }
    }

    for (int i=row,j=col ; i>=0 && j>=0 ; i--,j--) {
        if(board[i][j]) {
            return false;
        }
    }

    for (int i=row,j=col ; i<N && j>=0 ; i++,j-- ) {
        if(board[i][j]) {
            return false;
        }
    }

    return true;
}

void placeQueen(int col) {

    if (col == N) {
        printBoard();
        counts++;
        return;
    }
    for (int row=0 ; row<N ; row++) {
        if(canPlaceQueen(row,col)) {
            board[row][col] = 1;
            placeQueen(col+1);
            board[row][col] = 0;//backtrack
        }
    }
}

int main() {
    placeQueen(0);
    return 0;
}
