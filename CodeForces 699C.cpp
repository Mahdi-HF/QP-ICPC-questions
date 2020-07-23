#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, j;
    cin >> n;

    int arr[n + 2];
    int arr2[n + 2];
    int res[2][n + 2];

    for (int i = 0; i < n; i++){
        cin >> j;
        switch (j){
        case 0:
            arr[i] = 0;
            arr2[i] = 0;
            break;
        case 1:
            arr[i] = 0;
            arr2[i] = 1;
            break;
        case 2:
            arr[i] = 1;
            arr2[i] = 0;
            break;
        case 3:
            arr[i] = 1;
            arr2[i] = 1;
            break;
        default:
            break;
        }
    }

    res[0][0] = arr[0];
    res[1][0] = arr2[0];
    for (int i = 1; i < n; i++){
        res[0][i] = max(res[0][i - 1], res[1][i - 1] + arr[i]);
        res[1][i] = max(res[1][i - 1], res[0][i - 1] + arr2[i]);
    }
    int ans = max(res[0][n - 1], res[1][n - 1]);
    cout << n - ans << endl;

    return 0;
}