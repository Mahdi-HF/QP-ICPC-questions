#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
#define int long long

vector <int> food_price;
vector<int> res;
int arr[2000005];

void coin_change_modified(int d[], int n, int k){
    int M[n + 1];
    M[0] = 0;
    int S[n + 1];
    S[0] = 0;
    int i, j;
    for (j = 1; j <= n; j++){
        int minimum = INF;
        int coin = 0;
        for (i = 1; i <= k; i++){
            if (j >= d[i]){
                if ((1 + M[j - d[i]]) < minimum){
                    minimum = 1 + M[j - d[i]];
                    coin = i;
                }
            }
        }
        M[j] = minimum;
        S[j] = coin;
    }
    int l = n;
    while (l > 0){
        cout << S[l] << " ";
        l = l - d[S[l]];
    }
}

// int count(int number, int value){
//     if (value == 0) return 1;
//     if (value < 0) return 0;
//     if (number <= 0) return 0;
//     return count(number - 1, value) + count(number, value - food_price[number - 1]);
// }

int solve(int m, int value){
    int table[value + 1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for (int i = 0; i < m; i++)
        for (int j = food_price[i]; j <= value; j++)
            table[j] += table[j - food_price[i]];
    return table[value];
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, number;
    cin >> n;
    arr[0]=0;
    for (int i = 0; i < n; i++){
        int price;
        cin >> price;
        food_price.push_back(price);
        arr[i+1] = price;
    }
    cin >> number;
    for (int i = 0; i < number; i++){
        int value;
        cin >> value;
        int cnt = solve(food_price.size(), value);
        if (cnt == 0)
            cout << "Impossible" << endl;
        if (cnt == 1){
            coin_change_modified(arr, value, food_price.size());
        }
        if (cnt >= 2)
            cout << "Ambiguous" << endl;
    }
    return 0;
}

