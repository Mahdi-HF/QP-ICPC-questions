#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> out_time;
long long K[505][10005];

int knapSack(int W, vector<int> vec, int n){
    for (int i = 0; i <= n; i++){
        for (int w = 0; w <= W; w++){
            if (i == 0 or w == 0)
                K[i][w] = 0;
            else if (vec[i - 1] <= w)
                K[i][w] = max(vec[i - 1] + K[i - 1][w - vec[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int res = K[n][W];
    int w = W;
    for (int i = n; i > 0 and res > 0; i--) {
        if (res == K[i - 1][w])
            continue;
        else {
            out_time.push_back(i-1);
            res = res - vec[i - 1];
            w = w - vec[i - 1];
        }
    }
    return K[n][W];
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vec;
    int time, n, sum=0;
    cin >> time >> n;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        sum += num;
        vec.push_back(num);
    }
    knapSack(sum/2, vec, vec.size());
    int t1 = 0, t2 = 0;
    for(int i = 0; i < vec.size(); i++) {
        auto it = find(out_time.begin(), out_time.end(), i);
        if (it != out_time.end()) {
            cout << t1 << " ";
            t1 += vec[i];
        } else {
            cout << t2 << " ";
            t2 += vec[i];
        }
    }

    return 0;
}