#include<iostream>
#include<cstdio>
#define SIZE 5
using namespace std;

bool matrix[SIZE][SIZE];

void buildMatrix(){
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            matrix[i][j] = false;
}

void showMatrix(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout << matrix[i][j] << " ";
        }
        putchar('\n');
    }
}

void connectEdge(int initial, int goal){
    matrix[initial][goal] = matrix[goal][initial] = true;
}

int main(){
    int initial, goal;

    buildMatrix();

    cout << "Enter the initial and final point : ";
    cin >> initial >> goal;

    //build connection between two edges
    connectEdge(initial, goal);

    //display the current matrix
    showMatrix();

    return 0;
}
