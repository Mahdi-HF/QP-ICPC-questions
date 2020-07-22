#include <bits/stdc++.h>
using namespace std;
#define INF 10000000

struct edge {
    int a, b, value;
};

bool imp = 0;
vector<vector<int>> adj;

pair<int,int> dfs2(vector<int>& state, vector<bool>& vis, int curr) {
    if(vis[curr])
        return {0,0};
    vis[curr] = true;
    int AA = 0, BB = 0;
    if(state[curr] == 5)
        AA++;
    else
        BB++;

    for(auto next : adj[curr]) {
        if ((state[next] == 5 and state[curr] == 5) or (state[next] == -5 and state[curr] == -5))
            imp = true;

        else {
            if(state[curr] == 5)
                state[next] = -5;

            else 
                state[next] = 5;

            pair<int,int> p = dfs2(state, vis, next);
            AA += p.first;
            BB += p.second;
        }
    }
    return {AA, BB};
}

int dfs1(vector<int>& state, vector<bool>& vis, int curr) {
    if(vis[curr])
        return 0;
    vis[curr] = true;
    int count = 0;
    if(state[curr] == 1)
        count++;

    for(auto next : adj[curr]) {
        if ((state[next] == 1 and state[curr] == 1) or (state[next] == 0 and state[curr] == 0))
            imp = true;

        else {
            if(state[curr] == 0)
                state[next] = 1;

            else
                state[next] = 0;

            count += dfs1(state, vis, next);
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    int cost = 0;
    vector<int> state(n, -1);
    vector<bool> vis(n, false);
    adj.resize(n);

    vector<edge> zero;
    vector<edge> one;
    vector<edge> two;

    for (int i = 0; i < m; i++){
        edge e;
        cin >> e.a >> e.b >> e.value;
        e.a--;
        e.b--;

        if (e.value == 0)
            zero.push_back(e);

        if (e.value == 1){
            one.push_back(e);
            adj[e.a].push_back(e.b);
            adj[e.b].push_back(e.a);
        }

        if (e.value == 2)
            two.push_back(e);
    }

    for (auto i : zero){
        state[i.a] = 0;
        state[i.b] = 0;
    }

    for (auto i : two){
        if (state[i.a] == 0 or state[i.b] == 0)
            imp = true;

        state[i.a] = 1;
        state[i.b] = 1;
    }

    for (int i = 0; i < n; i++){
        if (!vis[i] and (state[i] == 1 or state[i] == 0))
            cost += dfs1(state, vis, i);
    }

    for (int i = 0; i < n; i++){
        if (!vis[i] and state[i] == -1){
            state[i] = 5;
            pair<int, int> p = dfs2(state, vis, i);
            cost += min(p.first, p.second);
        }
    }

    imp ? cout << "impossible" : cout << cost;
    cout << endl;

    return 0;
}