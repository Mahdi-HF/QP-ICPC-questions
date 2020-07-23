#include <bits/stdc++.h>
#define INF 10000000
using namespace std;
#define int long long

int n;
map <char, int> mp1;
map <int, char> mp2;
vector<string> words;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;

void dfs1(int v){
    visited[v] = true;
    for (int u : adj[v]){
        if (!visited[u])
            dfs1(u);
    }
    ans.push_back(v);
}

void topological_sort(){
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i){
        if (!visited[i])
            dfs1(i);
    }
}

bool is_possible = true;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v){
    color[v] = 1;
    for (int u : adj[v]){
        if (color[u] == 0){
            parent[u] = v;
            if (dfs(u))
                return true;
        }
        else if (color[u] == 1){
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle(){
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++){
        if (color[v] == 0 and dfs(v))
            break;
    }
    if(cycle_start != -1) {
        // vector<int> cycle;
        // cycle.push_back(cycle_start);
        // for (int v = cycle_end; v != cycle_start; v = parent[v])
        //     cycle.push_back(v);
        // cycle.push_back(cycle_start);
        // reverse(cycle.begin(), cycle.end());
        is_possible = false;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    string alefba = "abcdefghijklmnopqrstuvwxyz";
    int num = 0;
    n = 26;
    for (int i = 0; i < n; i++){
        mp1[alefba[i]] = num;
        mp2[num] = alefba[i];
        num++;
    }

    adj.resize(n+2);
    for (int i = 0; i < tc; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }

    for (int i = 0; i < tc - 1; i++){
        int p1 = 0;
        int p2 = 0;
        string str1 = words[i];
        string str2 = words[i + 1];
        while(true){
            if (str2.size() == p2){
                if (str1.size() != p1)
                    is_possible = false;
                break;
            }
            if (str1.size() == p1)
                break;

            if (str1[p1] == str2[p2]){
                p1++;
                p2++;
                continue;
            }
            else{
                int v1 = mp1[str2[p2]];
                int v2 = mp1[str1[p1]];
                adj[v1].push_back(v2);
                break;
            }
        }
    }

    find_cycle();
    if (!is_possible)
        cout << "Impossible" << endl;

    else{
        topological_sort();
        for (auto el: ans)
            cout << mp2[el];
        cout << endl;
    }
    return 0;
}