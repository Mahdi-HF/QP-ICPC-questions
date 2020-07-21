#include <bits/stdc++.h>
using namespace std;

int main(){
    string current, explosion;
    cin >> current;
    cin >> explosion;

    int h = stoi(explosion.substr(0,2)) - stoi(current.substr(0,2));
    if(h<0)
        h = 24 + h;
    int m = stoi(explosion.substr(3,2)) - stoi(current.substr(3,2));
    if(m<0)
    {
        m = 60 + m;
        h--;
        if(h<0)
            h = 24 + h;
    }
    int s = stoi(explosion.substr(6,2)) - stoi(current.substr(6,2));
    if(s<0)
    {
        s = 60 + s;
        m--;
        if(m<0)
            {
                m = 60 + m;
                h--;
                if(h<0)
                    h = 24 + h;
            }
    }
    if(h==0 and m==0 and s==0)
        h = 24;
    string hh = to_string(h);
    string mm = to_string(m);
    string ss = to_string(s);
    if(h<10)
        hh = "0" + hh;
    if(m<10)
        mm = "0" + mm;
    if(s<10)
        ss = "0" + ss;

    cout << hh << ":" << mm << ":" << ss << endl;
    return 0;
}