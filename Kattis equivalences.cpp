#include <bits/stdc++.h>
using namespace std;
#define SIZE 150005

vector<vector<int>> g(SIZE), gr(SIZE);
vector<bool> used(SIZE);
vector<int> order, component;

void dfs1(int v){
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs1(g[v][i]);
    order.push_back(v);
}

void dfs2(int v){
    used[v] = true;
    component.push_back(v);
    for (size_t i = 0; i < gr[v].size(); ++i)
        if (!used[gr[v][i]])
            dfs2(gr[v][i]);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int tc; cin >> tc;
    for (int i = 0; i < tc; i++){
        int X = 0, Y = 0, vertices = 0, n, m;
        cin >> n >> m;
        for (int j = 0; j < m; j++){
            int a, b; cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            gr[b].push_back(a);
        }

        if(n==1){
            cout << 0 << endl;
            g.clear();
            gr.clear();
            used.clear();
            order.clear();
            component.clear();

            g.resize(SIZE);
            gr.resize(SIZE);
            used.resize(SIZE);
            continue;
        }

        order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i)
            if (!used[i])
                dfs1(i);
        used.assign(n, false);
        for (int i = 0; i < n; ++i){
            int v = order[n - 1 - i];
            if (!used[v]){
                dfs2(v);

                vertices++;
                int in=0, out=0;
                set <int> cmp;
                cmp.clear();
                for(auto v: component)
                    cmp.insert(v);
                for (auto v : component){
                    for(auto ver: g[v]){
                        if(cmp.find(ver) == cmp.end())
                            out++;
                    }
                    for(auto ver: gr[v]){
                        if(cmp.find(ver) == cmp.end())
                            in++;
                    }
                }
                if (in == 0) X++;
                if (out == 0) Y++;
                component.clear();
            }
        }
        if (vertices == 1)
            cout << 0 << endl;
        else
            cout << max(X, Y) << endl;

        g.clear();
        gr.clear();
        used.clear();
        order.clear();
        component.clear();
        
        g.resize(SIZE);
        gr.resize(SIZE);
        used.resize(SIZE);
    }

    return 0;
}