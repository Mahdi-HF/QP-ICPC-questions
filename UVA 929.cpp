#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
vector<int> d, p;
int arr[1000][1000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--){
        int n, m;
        int num = 0;
        // mp2.clear();
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int c;
                cin >> c;
                arr[i][j] = c;
                pair<int, int> pr = {i, j};
                // mp2[pr] = num;
                num++;
            }
        }

        if(n == 1 and m == 1){
            cout << arr[0][0] << endl;
            continue;
        }

        adj.clear();
        adj.resize(num);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                // int vertex = mp2[{i,j}];
                int vertex = i*m + j;

                if (i!=n-1){
                    // int v2 = mp2[{i + 1, j}];
                    int v2 = (i+1)*m + j;
                    adj[vertex].push_back({v2, arr[i + 1][j]});
                }
                if (i!=0){
                    // int v2 = mp2[{i - 1, j}];
                    int v2 = (i - 1) * m + j;
                    adj[vertex].push_back({v2, arr[i - 1][j]});
                }
                if(j!=m-1){
                    // int v2 = mp2[{i, j+1}];
                    int v2 = i* m + j+1;
                    adj[vertex].push_back({v2, arr[i][j+1]});
                }
                if(j!=0){
                    // int v2 = mp2[{i, j-1}];
                    int v2 = i * m + j-1;
                    adj[vertex].push_back({v2, arr[i][j-1]});
                }
            }
        }

        int n1 = adj.size();
        int s = 0;
        d.assign(n1, INF);
        p.assign(n1, -1);
        d[s] = 0;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            if (d_v != d[v])
                continue;

            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push({d[to], to});
                }
            }
        }
        cout << d[num-1]+arr[0][0] << endl;
    }

    return 0;
}