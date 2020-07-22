#include <bits/stdc++.h>
using namespace std;

vector <long long> saved(35,0);
map <string, int> mp;
string word;

long long solve(int ind){
    if (saved[ind])
        return saved[ind];
    string part = word.substr(ind);
    long long sum = mp[part];
    int size = word.size() - ind;
    for (int i = 0; i < size ; i++){
        part = word.substr(ind, i+1);
        int score = mp[part];
        if (score)
            sum = (sum + (score * solve(ind + i + 1))) % 1000000007;
    }
    saved[ind] = sum;
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num >> word;
    for (int i = 0; i < num; i++){
        int n;
        string part;
        cin >> part >> n;
        mp.insert({part, n});
    }
    long long res = solve(0);
    cout << res << endl;

    return 0;
}