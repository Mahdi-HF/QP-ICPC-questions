#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
const int INF = 100000000;

struct edge{
    int a, b;
    double cost;
};

int n, v;
vector<edge> e;

void solve(int t){
    int m = e.size();
    vector<double> d(n, -INF);
    d[v] = 1;
    vector<int> p(n, -1);

    for (;;){
        bool any = false;
        for (int j = 0; j < m; ++j){
            if (d[e[j].a] > -INF){
                double val2 = d[e[j].a] * e[j].cost;
                if (d[e[j].b] < val2){
                    d[e[j].b] = val2;
                    p[e[j].b] = e[j].a;
                    any = true;
                }
            }
        }
        if (!any)
            break;
    }
    cout.precision(4);
    cout << fixed << d[t] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    while (1){
        int ver, edg;
        cin >> ver >> edg;
        if (ver == 0 and edg == 0)
            break;

        n = ver;
        int m = edg;
        v = 0;

        for (int i = 0; i < m; i++){
            int a, b;
            double val;
            cin >> a >> b >> val;

            edge ed;
            ed.a = a;
            ed.b = b;
            ed.cost = val;
            e.push_back(ed);

            ed.a = b;
            ed.b = a;
            e.push_back(ed);
        }
        solve(n-1);
        e.clear();
    }
    return 0;
}