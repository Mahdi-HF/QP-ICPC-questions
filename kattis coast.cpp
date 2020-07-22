#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005]; // 0 water, 1 land
int n = 0, m = 0, cnt = 0;
map<int, pair<int, int>> mp1;
map<pair<int, int>, int> mp2;
vector<vector<int>> adj(1020000);
vector<bool> visited(1020000);

void dfs(int v){
    visited[v] = true;
    int i = mp1[v].first;
    int j = mp1[v].second;

    if(arr[i+1][j]==1 and i!=n+1)
        cnt++;

    if(arr[i-1][j]==1 and i!=0)
        cnt++;

    if(arr[i][j+1]==1 and j!=m+1)
        cnt++;

    if(arr[i][j-1]==1 and j!=0)
        cnt++;

    for (int u : adj[v]){
        if (!visited[u])
            dfs(u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char cr;
            cin >> cr;
            arr[i][j] = toascii(cr)-48;
        }
    }

    int num = 0;
    for (int i = 0; i < n+2; i++){
        for (int j = 0; j < m+2; j++){
            pair<int, int> pr = {i, j};
            mp1[num] = pr;
            mp2[pr] = num;
            num++;
        }
    }

    for (int i = 0; i < n+2; i++){
        for (int j = 0; j < m+2; j++){
            if(arr[i][j] == 0){
                int vertex = mp2[{i,j}];
                if (i!=n+1){
                    if(arr[i+1][j]==0)
                        adj[vertex].push_back(mp2[{i + 1, j}]);
                }
                if (i!=0){
                    if(arr[i-1][j]==0)
                        adj[vertex].push_back(mp2[{i - 1, j}]);
                }
                if(j!=m+1){
                    if(arr[i][j+1]==0)
                        adj[vertex].push_back(mp2[{i, j + 1}]);
                }
                if(j!=0){
                    if (arr[i][j-1] == 0)
                        adj[vertex].push_back(mp2[{i, j - 1}]);
                }
            }
        }
    }

    dfs(0);
    cout << cnt << endl;
    
    return 0;
}