#include <bits/stdc++.h>
using namespace std;

int n = 0;
bool adj[105][105];

void printSolution(int color[]);

bool isSafe(int v, int color[], int c){
    for (int i = 0; i < n; i++)
        if (adj[v][i] and c == color[i])
            return false;
    return true;
}

bool graphColoringUtil (int m, int color[], int v) { 
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, color, c)){
            color[v] = c;
            if (graphColoringUtil(m, color, v + 1) == true)
                return true; 
            color[v] = 0;
        }
    } 
    return false; 
}

bool graphColoring(int m){
    int color[n];
    for (int i = 0; i < n; i++)
        color[i] = 0;

    if (graphColoringUtil(m, color, 0) == false){
        printf("Solution does not exist");
        return false;
    }
    printSolution(color);
    return true;
}

void printSolution(int color[]){
    for (int i = 0; i < n; i++)
        cout << i+1 << " " << color[i] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;

    cin.ignore();
    string str;
    set <pair<int, int>> sss;
    while(getline(cin, str)){
        auto it = str.find('-');
        string a_s = str.substr(0, it);
        string b_s = str.substr(it+1);
        int a = stoi(a_s) - 1;
        int b = stoi(b_s) - 1;
        if (sss.find({a, b}) == sss.end()){
            sss.insert({a, b});
            sss.insert({b, a});
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
    }
    graphColoring(4);

    return 0;
}