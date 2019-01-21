#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

int main(){
    int N, E, a, b, i, j, x, visited[100] = {0}, S, parent[100], dis[100];
    bool flag;

    vector<int> adjList[100];
    queue<int> bfsQueue;

    cout << "How many nodes && edges: ";
    cin >> N >> E;

    cout << "Enter the edges: ";
    for(i=0; i<E; i++){
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    cout << "Enter the starting node: ";
    cin >> S;

    visited[S] = 1;
    bfsQueue.push(S);
    dis[S] = 0;

    putchar('\n');
    cout << "Level of " << S << ": " << dis[S] << endl;

    while(!bfsQueue.empty()){
        x = bfsQueue.front();
        bfsQueue.pop();
        for(j=0; j<adjList[x].size(); j++){
            if(visited[adjList[x][j]] == 0){
                bfsQueue.push(adjList[x][j]);
                visited[adjList[x][j]] = 1;
                parent[adjList[x][j]] = x;
                dis[adjList[x][j]] = dis[parent[adjList[x][j]]]+1;
                cout << "Level of " << adjList[x][j] << ": " << dis[adjList[x][j]] << endl;
                cout << "Parent: " << parent[adjList[x][j]] << endl;
            }
        }
    }

    return 0;
}
