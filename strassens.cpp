#include <iostream>
using namespace std;

void strassen(double a[2][2], double b[2][2], double c[2][2]) {
    double p1 = a[0][0] * (b[0][1] - b[1][1]);
    double p2 = (a[0][0] + a[0][1]) * b[1][1];
    double p3 = (a[1][0] + a[1][1]) * b[0][0];
    double p4 = a[1][1] * (b[1][0] - b[0][0]);

    double p5 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    double p6 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
    double p7 = (a[0][0] - a[1][0]) * (b[0][0] + b[0][1]);

    c[0][0] = p5 + p4 - p2 + p6;
    c[0][1] = p1 + p2;
    c[1][0] = p3 + p4;
    c[1][1] = p5 + p1 - p3 - p7;
}

int main() {
    double a[2][2] ={
        {1,2},{3,4}
    };
    double b[2][2] = {
        {1,2},
        {3,4}
        };
    double c[2][2];

    strassen(a, b, c);
    cout << "The result of multiplication is:" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
