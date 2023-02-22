#include<bits/stdc++.h>
using namespace std;

#define MAX_VERTICES 6

int w[MAX_VERTICES][MAX_VERTICES]; // shortest path distances
int L[MAX_VERTICES][MAX_VERTICES]; // shortest path distances
int l[MAX_VERTICES][MAX_VERTICES]; // shortest path distances

// Function to print the shortest path from vertex i to j

// Function to run the Floyd-Warshall algorithm
void floydWarshall(int vertices){
    for ( int m = 2; m < vertices; m++ ){
        cout<<"-----------------"<<endl;
        cout<<m<<endl;
        int min = 87;
        for (int i = 0; i < vertices; i++){
            for (int j = 0; j < vertices; j++){
                min = 87;
                for (int k = 0; k < vertices; k++){
                    if(L[i][k] == 87 || w[k][j] == 87) continue;
                    if(min > L[i][k] + w[k][j]) min = L[i][k] + w[k][j];
                }
                l[i][j] = min;
            }
        }
        for (int i = 0; i < vertices; i++){
            for (int j = 0; j < vertices; j++){                
                L[i][j] = l[i][j];
                cout<<L[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

int main(){
    // Number of vertices in the graph
    int vertices;
    cin>>vertices;

    // Number of edges in the graph

    // initialize distance array
    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            cin>>w[i][j];
            L[i][j] = w[i][j];
        }
    }
    floydWarshall(vertices);
}
