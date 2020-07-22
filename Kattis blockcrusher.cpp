#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 10000000;
vector<vector<pair<int, int> > > adj;

void dijkstra(int s, vector<int> &d, vector<int> &p)
{
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const &p)
{
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    // reverse(path.begin(), path.end());
    return path;
}

pair <int, int> matrix[25][65];

int32_t main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);cout.tie(NULL);

    while(1){
        int n, m;
        cin >> n >> m;
        if (n == 0 and m == 0)
            break;

        int val = 1;
        adj.clear();
        adj.resize((n * m) + 2);

        for (int i = 0; i < n + 3; i++)
        {
            for (int j = 0; j < m + 3; j++)
                matrix[i][j] = make_pair(- 1, -1);
        }

        for (int i = 0; i < n; i++)
        {
            getchar();
            for (int j = 0; j < m; j++)
            {
                char c = getchar();
                int num = c - '0';
                matrix[i + 1][j + 1] = make_pair(val, num);
                val++;
            }
        }

        for (int i = 1; i < m + 1; i++)
            adj[0].push_back(matrix[1][i]);

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                int ver = matrix[i][j].first;

                pair<int, int> ver1 = matrix[i + 1][j - 1];
                pair<int, int> ver2 = matrix[i + 1][j];
                pair<int, int> ver3 = matrix[i + 1][j + 1];

                pair<int, int> ver4 = matrix[i][j - 1];
                pair<int, int> ver5 = matrix[i][j + 1];
                
                pair<int, int> ver6 = matrix[i - 1][j - 1];
                pair<int, int> ver7 = matrix[i - 1][j];
                pair<int, int> ver8 = matrix[i - 1][j + 1];

                if (ver1.first != -1)
                    adj[ver].push_back(ver1);

                if (ver2.first != -1)
                    adj[ver].push_back(ver2);

                if (ver3.first != -1)
                    adj[ver].push_back(ver3);

                if (ver4.first != -1)
                    adj[ver].push_back(ver4);

                if (ver5.first != -1)
                    adj[ver].push_back(ver5);

                if (ver6.first != -1)
                    adj[ver].push_back(ver6);

                if (ver7.first != -1)
                    adj[ver].push_back(ver7);

                if (ver8.first != -1)
                    adj[ver].push_back(ver8);
            }
        }

        int des = val;

        for (int i = 1; i < m + 1; i++)
            adj[(n - 1) * m + i].push_back(make_pair(des, 0));

        vector<int> p;
        vector<int> d;

        dijkstra(0, d, p);
        vector<int> path = restore_path(0, des, p);

        set<int> st;
        for (auto el : path)
            st.insert(el);

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (st.find(matrix[i][j].first) == st.end())
                    cout << matrix[i][j].second;
                else
                    cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}