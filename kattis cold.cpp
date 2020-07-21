#include <bits/stdc++.h>
using namespace std;

int n, res;

int main(){

    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            if(num < 0)
                res++;
        }
        cout << res << endl;
        res = 0;
    }

    return 0;
}