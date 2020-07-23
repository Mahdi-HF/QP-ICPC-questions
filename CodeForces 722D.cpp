#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tc;
    cin >> tc;
    set<int> st;
    set<int> arr;

    if(tc == 1){
        cout << "1" << endl;
        exit(0);
    }

    int min = INT_MAX;
    for (int i = 0; i < tc; i++){
        int num;
        cin >> num;
        arr.insert(num);
        st.insert(num);
        if(num < min)
            min = num;
    }

    while(min != 0){
        int valll = *arr.rbegin();
        int val = *arr.rbegin() / 2;
        if(st.find(val) == st.end()){
            arr.erase(valll);
            arr.insert(val);
            st.insert(val);
            if(val < min)
                min = val;
            continue;
        }

        else{
            while(1){
                val = val / 2;
                if(st.find(val) == st.end()){
                    arr.erase(valll);
                    arr.insert(val);
                    st.insert(val);
                    if (val < min)
                        min = val;

                    if (min == 0){
                        st.erase(0);
                        arr.erase(val);
                        arr.insert(valll);
                        break;
                    }
                    break;
                }
            }
        }
    }

    for (auto it = arr.rbegin(); it != arr.rend(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}