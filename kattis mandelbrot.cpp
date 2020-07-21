#include <bits/stdc++.h>
using namespace std;

int r;
float x, y;

int func(int r,float c)
{
    if(r == 0)
        return 0;
    float res = pow(func(r-1,c),2) + c;
    return res;
}

int main(){

    while(cin>>x>>y>>r)
    {
        float c = sqrt(x+y);
        float res = func(r,c);

        if(res > 1000)
            cout << "OUT" << endl;
        else 
            cout << "IN" << endl;
    }

    return 0;
}