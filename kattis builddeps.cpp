#include <bits/stdc++.h>
using namespace std;

int n = 0;
map<int, string> mp1;
map<string, int> mp2;
vector<vector<int>> adj(1000005);
vector<bool> visited(1000005);
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int num = 0;
    cin.ignore();
    for (int i = 0; i < n; i++){
        string line; getline(cin, line);
        auto sep = line.find(":");
        string topic = line.substr(0, sep);
        string rest = line.substr(sep+1);

        if(mp2.find(topic) == mp2.end()){
            mp1[num] = topic;
            mp2[topic] = num;
            num++;
        }

        if(rest.size() != 0){
            rest += " ";
            rest = rest.substr(1);
        }

        int topic_num = mp2[topic];
        while(rest.size() != 0){
            sep = rest.find(" ");
            string dep = rest.substr(0, sep);

            if (mp2.find(dep) == mp2.end()){
                mp1[num] = dep;
                mp2[dep] = num;
                num++;
            }
            adj[mp2[dep]].push_back(topic_num);
            rest = rest.substr(sep+1);
        }
    }
    string changed_file; cin >> changed_file;
    int changed_file_num = mp2[changed_file];

    dfs(changed_file_num);
    reverse(ans.begin(), ans.end());

    for(auto el: ans){
        cout << mp1[el] << endl;
    }

    return 0;
}