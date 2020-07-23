#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

int d[1000][1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;t--;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        d[u][v] = 1;
        d[v][u] = 1;
    }

    for (int k = 0; k < n; ++k){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (d[i][k] < INF and d[k][j] < INF){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    // d[i][j] = d[j][i];
                }
            }
        }
    }

    int cnt=0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (d[i][j] != 1){
                if(d[s][i] + d[j][t] + 1 >= d[s][t] and d[s][j] + d[i][t] + 1 >= d[s][t])
                    cnt++;
            }            
        }
    }
    cout << cnt << endl;
    return 0;
}