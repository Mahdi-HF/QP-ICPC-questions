#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n1, n2, res;

int main(){

    while(cin>>n1)
    {
        cin >> n2;
        res = n1 - n2;
        if(res<0)
            res *= -1;
        cout << res << endl;
    }

    return 0;
}