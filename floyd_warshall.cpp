#include<iostream>
using namespace std;

const int INF = 9999;

int main(){
    const int n = 3;
    int graph[n][n] = {

        {0,4,11},
        {6 , 0 ,2 },
        {3,INF , 0},
    };


    for (int k = 0 ; k < n ; k++){
        for(int i  = 0 ; i < n ; i++){
            for(int j  = 0 ; j < n ; j++){
                if (graph[i][k]+graph[k][j]<graph[i][j]){
                    graph[i][j]= graph[i][k]+graph[k][j];
                }
            }
        }
    }

     for(int i  = 0 ; i < n ; i++){
            for(int j  = 0 ; j < n ; j++){

                cout<<graph[i][j]<<" ";

            }
            cout<<endl;
        }

    return 0;
}
