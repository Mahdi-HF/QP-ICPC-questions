#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector <int> vi;

int32_t main(){
    int time=0, count=0;
    int n, t;
    int a, b, c, t0;
    cin >> n >> t;
    cin >> a >> b >> c >> t0;
    vi.push_back(t0); 
    for (int i = 0; i < (n-1); i++){
        int newT = (((a * vi[i]) + b) % c) + 1;
        vi.push_back(newT);
    }
    sort(vi.begin(), vi.end());

    int tillnow=0;
    for (int i = 0; i < n; i++){
        if (vi[i] > t)
            break;
        time += vi[i]+tillnow;
        tillnow += vi[i];
        t -= vi[i];
        count++;
        time = time % 1000000007;
    }
    cout << count << " " << time;

    return 0;
}