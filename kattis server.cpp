#include <bits/stdc++.h>
using namespace std;

int n, t, res;

int main(){

    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(t-num >= 0)
        {
            res++;
            t -= num;
        }
        else break;
    }

    cout << res;
    return 0;
}