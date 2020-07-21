#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> vi;
vector<int> vi2;

int32_t main(){
    int t;
    cin >> t;
    for (int j = 0; j < t; j++){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            int num;
            cin >> num;
            vi.push_back(num);
        }
        for (int i = 0; i < n; i++){
            int num2;
            cin >> num2;
            vi2.push_back(num2);
        }
        sort(vi.begin(), vi.end());
        sort(vi2.begin(), vi2.end());
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += vi[i] * vi2[n - i - 1];
        cout << "Case #" << j + 1 << ": " << sum << endl;
        vi.clear();
        vi2.clear();
    }
    return 0;
}