#include <bits/stdc++.h>
using namespace std;

//const int N = 4;
const int N = 3;
int final[N][N] = {
//    {1, 2, 3, 4},
//   {5, 6, 7, 8},
//    {9, 10, 11, 12},
//    {13, 14, 15, 0}
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0},
};

int row[] = {-1, 0, 1, 0};
int col[] = {0, -1, 0, 1};

struct Node {
    int puzzle[N][N];
    int x, y;
    int level;
    int cost;
    Node* parent;
};

int calculateCost(int initial[N][N], int final[N][N]) {
    int cost = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (initial[i][j] && initial[i][j] != final[i][j]) { //non-blank tile which is incorrect
                int x = (initial[i][j] - 1) / N;
                int y = (initial[i][j] - 1) % N;
                cost += abs(x - i) + abs(y - j);
            }
        }
    }
    return cost;
}

Node* newNode(int puzzle[N][N], int x, int y, int newX, int newY, int level, Node* parent) {
    Node* node = new Node;
    memcpy(node->puzzle, puzzle, sizeof(node->puzzle));
    swap(node->puzzle[x][y], node->puzzle[newX][newY]);
    node->cost = calculateCost(node->puzzle, final);
    node->level = level;
    node->x = newX;
    node->y = newY;
    node->parent = parent;
    return node;
}

void printMatrix(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }
}

void printPath(Node* node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    cout << endl;
    printMatrix(node->puzzle);
    cout << "--------" << endl;
}

struct comp {
    bool operator()(Node* a, Node* b) {
        return (a->cost + a->level) > (b->cost + b->level);
    }
};

void solve(int puzzle[N][N], int x, int y) {
    priority_queue<Node*, vector<Node*>, comp> pq;
    Node* root = newNode(puzzle, x, y, x, y, 0, NULL);
    root->cost = calculateCost(puzzle, final);
    pq.push(root);
    while (!pq.empty()) {
        Node* minCostNode = pq.top();
        pq.pop();
        if (minCostNode->cost == 0) {
            printPath(minCostNode);
            return;
        }
        for (int i = 0; i < N; i++) {
            int newX = minCostNode->x + row[i];
            int newY = minCostNode->y + col[i];
            if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
                Node* child = newNode(minCostNode->puzzle, minCostNode->x, minCostNode->y, newX, newY, minCostNode->level + 1, minCostNode);
                pq.push(child);
            }
        }
    }
}

int main() {
    int puzzle[N][N] = {
      //  {1, 5, 8},
        //{2, 7, 4},
        //{3, 6, 0},
                {0, 6, 2},
        {7, 1, 5},
        {8, 3, 4},
    };
    int x = 0, y = 0;
    solve(puzzle, x, y);
    return 0;
}
