#include <bits/stdc++.h>
using namespace std;

map <string, int> mp1;
map<int, string> mp2;
vector<int> all;
set <string> jesse;
set <string> walter;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> color_vec;
int n;

vector<vector<int>> adj1;
vector<bool> visited1;
bool imp = 0;
int n1;

void dfs1(int v){
    visited1[v] = true;
    for (int u : adj1[v]){
        if(color_vec[v] == color_vec[u]){
            imp = 1;
            break;
        }
        if (!visited1[u])
            dfs1(u);
    }
}

void dfs(int v, int color){
    visited[v] = true;
    color_vec[v] = color;

    for (int u : adj[v]){
        if (!visited[u]){
            if (color == 1)
                dfs(u, 2);
            else if (color == 2)
                dfs(u, 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tc;
    cin >> tc;
    n = tc;
    n1 = tc;
    adj.resize(n);
    color_vec.resize(n);
    visited.resize(n);

    adj1.resize(n);
    visited1.resize(n);

    int val = 0;
    for (int i = 0; i < tc; i++){
        string str;
        cin >> str;
        mp1[str] = val;
        mp2[val] = str;
        all.push_back(val);
        val++;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        int aa = mp1[a];
        int bb = mp1[b];
        adj[aa].push_back(bb);
        adj[bb].push_back(aa);

        adj1[aa].push_back(bb);
        adj1[bb].push_back(aa);
    }

    for(auto ver: all){
        if(visited[ver] == 0)
            dfs(ver, 1);
    }

    for(auto ver: all){
        if(visited1[ver] == 0)
            dfs1(ver);
    }

    if(imp == 1){
        cout << "impossible" << endl;
        exit(0);
    }

    for (int i = 0; i < n; i++){
        if (color_vec[i] == 1)
            jesse.insert(mp2[i]);

        else if (color_vec[i] == 2)
            walter.insert(mp2[i]);
    }

    for (auto el: walter)
        cout << el << " ";

    cout << endl;
    for (auto el: jesse)
        cout << el << " ";

    return 0;
}