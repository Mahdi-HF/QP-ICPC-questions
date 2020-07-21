#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector <vector<int>> adj;
vector <bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]){
            dfs(u);
        }
    }
}

int32_t main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        vector < pair <int,int> > vec;
        map <pair<int, int>, int> mp2;
        
        adj.resize(num + 5);
        visited.resize(num + 5);
        fill(visited.begin(), visited.end(), 0);
        
        for (int j = 0; j < (num+2); j++){
            int x, y;
            cin >> x >> y;
            pair<int, int> pr = make_pair(x, y);
            vec.push_back(pr);
            mp2[pr] = j;
        }
        for (int j = 0; j < (num+2); j++){
            int x1 = vec[j].first;
            int y1 = vec[j].second;
            adj[j].push_back(mp2[vec[j]]);

            for (int k = 0; k < (num+2); k++){
                if (j == k) continue;
                int x2 = vec[k].first;
                int y2 = vec[k].second;

                int xx = x2 - x1;
                int yy = y2 - y1;
                // int dif = pow(xx, 2) + pow(yy, 2);
                if (abs(xx) + abs(yy) <= 1000)
                    adj[j].push_back(mp2[vec[k]]);
            }
        }
        dfs(0);
        if (visited[num+1] == true)
            cout << "happy" << endl;
        else
            cout << "sad" << endl;

        adj.clear();
        visited.clear();
        mp2.clear();
        vec.clear();
    }
    return 0;
}
