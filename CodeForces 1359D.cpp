#include <bits/stdc++.h>
using namespace std;
#define INF (INT32_MAX-100)
#define SIZE 100000005

vector<int> arr;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    arr.resize(n+2);
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr[i] = num;
    }

    int ans=0;
    for (int i = 1; i <= 30; i++)
    {
        int res = 0;
        for(auto el: arr){
            res += el;
            if(el>i)
                res = 0;
            res = max(res,0);
            ans = max(ans,res-i);
        }
    }
    cout << ans << endl;
    return 0;
}