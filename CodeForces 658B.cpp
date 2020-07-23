#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, k, q;
    cin >> n >> k >> q;

    int arr[n + 5];
    map<int, int> mp;
    for (int i = 1; i < n+1; i++){
        int x;
        cin >> x;
        arr[i] = x;
    }

    set<pair<int,int>> display;
    display.clear();

    while(q--){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            if(display.size() < k){
                display.insert({arr[b],b});
                continue;
            }
            int now_value = arr[b];
            for(auto el: display){
                if(el.first < now_value){
                    display.erase(el);
                    display.insert({arr[b], b});
                    break;
                }
            }
        }
        int found = 0;
        if(a == 2){
            for(auto el: display){
                if(el.second == b){
                    found = 1;
                    break;
                }
            }

            if(found == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}