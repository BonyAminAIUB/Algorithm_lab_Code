#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];

void DFS(int source){
    cout << source << " ";
    visited[source] = true;
    for(int child : adj_list[source]){
        if(!visited[child]){
            DFS(child);
        }
    }
}

int MCM(int arr[], int n){
    int c[n+1][n+1]; 
    for(int i = 1; i < n; i++){
        c[i][i] = 0;
    }
    for(int i = 2; i < n; i++){
        for (int j = 1; j < n - i + 1; j++){
            int end = j + i - 1;
            c[j][end] = INT_MAX;
            for(int k = j; k < end; k++){
                int cost = c[j][k] + c[k+1][end] + arr[j-1]*arr[k]*arr[end];
                if(cost < c[j][end]){
                    c[j][end] = cost;
                }
            }
        }
    }

    return c[1][n-1]; 
}
int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited,false,sizeof(visited));
    cout << "DFS traversal: ";
    for(int i = 0; i<n; i++){  //  disconnected graph er jonno
        if(!visited[i]){
            DFS(i);
        }
    }
    cout << endl;

    int n1;
    cin >> n1;
    int arr[n1+1]; 
   
    for(int i = 0; i <= n1; i++){
        cin >> arr[i];
    }
    cout<< "Minimum cost: " << MCM(arr, n1+1) << endl;

    return 0;
}