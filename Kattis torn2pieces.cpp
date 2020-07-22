#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 100000
#define SIZE 50

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int> > adj(SIZE);
    map<int, string> mp1;
    map<string, int> mp2;
    int n, num = 0;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        string line = "";
        getline(cin, line);

        auto sep = line.find(" ");
        string src = line.substr(0, sep);
        string rest = line.substr(sep + 1);

        if (mp2.find(src) == mp2.end()){
            mp1[num] = src;
            mp2[src] = num;
            num++;
        }

        if (rest.size() != 0)
            rest += " ";

        int src_num = mp2[src];

        while (rest.size() != 0){
            sep = rest.find(" ");
            string station = rest.substr(0, sep);

            if (mp2.find(station) == mp2.end()){
                mp1[num] = station;
                mp2[station] = num;
                num++;
            }
            int station_num = mp2[station];

            bool exist1 = 0;
            for (int j = 0; j < adj[station_num].size(); j++){
                if(adj[station_num][j] == src_num)
                    exist1 = 1;
            }
            if(!exist1) adj[station_num].push_back(src_num);

            bool exist2 = 0;
            for (int j = 0; j < adj[src_num].size(); j++){
                if (adj[src_num][j] == station_num)
                    exist2 = 1;
            }
            if(!exist2) adj[src_num].push_back(station_num);

            rest = rest.substr(sep + 1);
        }
    }

    string last_line;
    getline(cin, last_line);
    auto seperator = last_line.find(" ");
    string start = last_line.substr(0, seperator);
    string end = last_line.substr(seperator + 1);

    int start_num = INF;
    if (mp2.find(start) != mp2.end()) start_num = mp2[start];

    int end_num = INF;
    if (mp2.find(end) != mp2.end()) end_num = mp2[end];

    if(end_num == INF or start_num == INF){
        cout << "no route found";
        return 0;
    }

    queue<int> q;
    vector<bool> used(SIZE);
    vector<int> d(SIZE), p(SIZE);

    int s = start_num;
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
            if (!used[u]){
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    if (!used[end_num])
        cout << "no route found";
    else {
        vector<int> path;
        for (int v = end_num; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        for (int v : path)
            cout << mp1[v] << " ";
    }
    cout << endl;

    return 0;
}