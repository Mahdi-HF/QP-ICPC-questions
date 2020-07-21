#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<pair<int, int>> vp;

int32_t main(){
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        int fir, sec;
        cin >> fir >> sec;
        vp.push_back(make_pair(fir, sec));
    }
    int sum = 0;
    for (int i = t; i >= 0; i--){
        int max_value = 0;
        int max_ind = 0;
        for (int j = 0; j < n; j++){
            int f = vp[j].first;
            int s = vp[j].second;
            if (s >= i and max_value < f){
                max_ind = j;
                max_value = f;
            }
        }
        if (max_value != 0) vp[max_ind] = make_pair(-1, -1);
        sum += max_value;
    }
    cout << sum << endl;
    return 0;
}