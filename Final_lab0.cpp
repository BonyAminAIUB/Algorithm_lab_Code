#include <bits/stdc++.h>
using namespace std;
const int infinity = 1e9;

int main(){
    int n, e;
    cin >> n >> e; 

    vector<vector<int>> dis(n, vector<int>(n, infinity));
    vector<vector<int>> par(n, vector<int>(n, -1)); 

    for(int i = 0; i<n; i++){
        dis[i][i] = 0;
        par[i][i] = i;
    }

    while(e--){
        int a,b,w;
        cin >> a >> b >> w;
        dis[a][b] = w; 
        par[a][b] = a;
    }

    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(dis[i][k] < infinity && dis[k][j] < infinity){
                    if(dis[i][j] > dis[i][k] + dis[k][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                        par[i][j] = par[k][j];
                    }
                }
            }
        }
    }

    // Output distance matrix
    cout << "Distance Matrix:" << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(dis[i][j] == infinity){
                cout << "Infinite";
            }  
            else{
                cout << dis[i][j] << "\t";
            }  
        }
        cout << endl;
    }

    // Output parent matrix
    cout << endl << "Parent Matrix:" << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << par[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}