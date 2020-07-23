#include <bits/stdc++.h>
using namespace std;
// #define INF INT32_MAX-100
#define SIZE 100000005
#define int long long

set <int> st;
set <int> st2;
int arr[SIZE];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc){
        int n, r = 0, l = 0;
        cin>>n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        while(true){
            if (r >= n) break;

            while(st.count(arr[r]) == 0){
                st.insert(arr[r]);
                r++;
                if (r >= n) break;
            }
            st2.insert(r-l);
            st.erase(arr[l]);
            l++;
        }

        int number = 0;
        for(auto el: st2){
            if(el > number)
                number = el;
        }
        cout << number << endl;
        st.clear();
        st2.clear();
        tc--;
    }

    return 0;
}