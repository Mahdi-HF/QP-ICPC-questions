#include <bits/stdc++.h>
using namespace std;

vector <int> v;
set <int> res;
int w, p;

int main(){
    cin>>w>>p;

    v.push_back(0);
    for(int i=1;i<=p;i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    v.push_back(w);

    for(int i=(p+1);i>0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            int num = v[i] - v[j];
            res.insert(num);
        }
    }

    for (auto itr = res.begin(); itr != res.end(); ++itr) 
    { 
        cout << *itr << ' ';
    } 
    cout << endl; 

    return 0;
}