#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> parent, rankkk;

void make_set(int v)
{
    parent[v] = v;
    rankkk[v] = 0;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rankkk[a] < rankkk[b])
            swap(a, b);
        parent[b] = a;
        if (rankkk[a] == rankkk[b])
            rankkk[a]++;
    }
}

struct Edge{
    int u, v, weight;
};

bool mycmp(const Edge &l, const Edge &r){
    return l.weight <= r.weight;
}

bool mycmp2(const Edge &l, const Edge &r)
{
    if (l.u == r.u)
        return l.v < r.v;
    return l.u < r.u;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    while(1){
        int v, e;
        cin >> v >> e;
        if(v == 0 and e == 0) break;

        int n = v;
        int cost = 0;
        parent.clear();
        rankkk.clear();
        parent.resize(n+5);
        rankkk.resize(n+5);

        vector<Edge> edges;
        vector<Edge> result;

        for (int i = 0; i < n+2; i++)
            make_set(i);

        for (int i = 0; i < e; i++){
            int a, b, val;
            cin >> a >> b >> val;
            Edge ed;

            if (a < b){
                ed.u = a;
                ed.v = b;
            }
            else{
                ed.u = b;
                ed.v = a;
            }
            
            ed.weight = val;
            edges.push_back(ed);
        }

        sort(edges.begin(), edges.end(), mycmp);

        for (Edge e : edges)
        {
            if (find_set(e.u) != find_set(e.v))
            {
                cost += e.weight;
                result.push_back(e);
                union_sets(e.u, e.v);
            }
        }

        sort(result.begin(), result.end(), mycmp2);

        if(result.size() != n-1)
            cout << "Impossible" << endl;

        else
        {
            cout << cost << endl;
            for (auto el : result)
            {
                int uu = el.u;
                int vv = el.v;
                if (uu < vv)
                    cout << uu << " " << vv << endl;
                else
                    cout << vv << " " << uu << endl;
            }
        }
    }

    return 0;
}