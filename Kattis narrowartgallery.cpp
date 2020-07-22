#include <bits/stdc++.h>
using namespace std;
#define INF 20000000

vector <vector<int>> vec(210);
int arr2[200][200][200];

int solve(int cur_row, int closed, int tile){ // right is 1 and left is zero other -1
    if(arr2[cur_row][closed][tile] != 0) return arr2[cur_row][closed][tile];
    if (!closed) return 0;
    if (!cur_row) return INF;
    int data1 = solve(cur_row - 1, closed, -1);
    int data2 = INF;
    int data3 = INF;
    if(tile != 1)
        data2 = vec[cur_row-1][0] + solve(cur_row - 1, closed - 1, 0);
    if(tile != 0)
        data3 = vec[cur_row-1][1] + solve(cur_row - 1, closed - 1, 1);
    int semi_final = min(data1, data2);
    int final = min(semi_final, data3);
    arr2[cur_row][closed][tile] = final;
    return final;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        vec[i].push_back(x);
        vec[i].push_back(y);
        sum += x+y;
    }
    int res = solve(n, k, -1);
    cout << sum-res << endl;

    return 0;
}