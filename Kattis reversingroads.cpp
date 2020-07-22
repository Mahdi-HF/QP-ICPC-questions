#include <bits/stdc++.h>
using namespace std;
#define SIZE 5500
#define int long long

vector<vector<int>> g, gr;
vector<pair<int, int>> all, all_editted;
vector<bool> used;
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

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int m, n, tc = 0; // m for vertex n for edges
    while (cin >> m >> n){
        all.clear();
        for (int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            all.push_back({a, b});
        }

        bool my_status = 0;
        string rev_edge = "";
        for (int k = 0; k <= n; k++){
            if (m > n and n != 0) break;
            if (m > 1 and n == 0) break;
            if (m == 1){
                my_status = 1;
                break;
            }

            all_editted.clear();
            all_editted = all;
            int j = k-1;
            if(j>=0){
                int a = all_editted[j].first;
                int b = all_editted[j].second;
                all_editted[j] = {b, a};
                rev_edge = to_string(a) + " " + to_string(b);
            }
            j++;

            g.clear();
            gr.clear();
            g.resize(SIZE);
            gr.resize(SIZE);
            component.clear();
            order.clear();
            for (auto el : all_editted){
                int a = el.first;
                int b = el.second;
                g[a].push_back(b);
                gr[b].push_back(a);
            }

            used.assign(n, false);
            for (int i = 0; i < n; ++i)
                if (!used[i])
                    dfs1(i);

            used.assign(n, false);
            for (int i = 0; i < n; ++i){
                int v = order[n - 1 - i];
                if (!used[v]){
                    dfs2(v);
                    if (component.size() == m){
                        my_status = 1;
                        k = n+5;
                        component.clear();
                        break;
                    }
                    component.clear();
                }
            }
        }

        string res;
        if (my_status == 1)
            res = "valid";
        if (my_status == 0)
            res = "invalid";
        if (my_status == 1  and !rev_edge.empty())
            res = rev_edge;
        rev_edge = "";

        cout << "Case " << tc+1 << ": " << res << endl;
        tc++;
    }

    return 0;
}