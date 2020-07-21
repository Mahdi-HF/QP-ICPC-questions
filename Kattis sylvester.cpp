#include <bits/stdc++.h>
using namespace std;

int val(int x, int y, unsigned long long n){
    int v = 1;
    while (!(n & 1)){
        n >>= 1;
        if (x < n){
            if (y >= n)
                y -= n;
        }
        else{
            x -= n;
            if (y >= n){
                y -= n;
                v = -v;
            }
        }
    }
    return v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for (int i = 0; i < t; i++){
        unsigned long long n;
        int x, y, w, h;
        cin >> n >> x >> y >> w >> h;
        for (int yy = y; yy < y + h; yy++){
            if (w) cout << val(x, yy, n) << " ";
            for (int xx = x + 1; xx < x + w; xx++)
                cout << val(xx, yy, n) << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}