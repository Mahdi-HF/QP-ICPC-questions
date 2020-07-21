#include <bits/stdc++.h>
using namespace std;

char my_hash(string st) {
    char res = st[0];
    for (int i = 1; i < st.length(); i++) {
        char c = st[i];
        res = c ^ res;
    }
    // cout << st << " hash is: " << res << endl;
    return res;
}

int main(){
    while (1) {
        vector <string> vs;
        int n = 0, unique = 0, collisions = 0, first = 1;
        cin >> n;
        getchar();
        if(n==0) break;
        for (int i = 0; i < n; i++) {
            string str;
            getline(cin, str);
            vs.push_back(str);
        }
        set <string> st;
        for (int i = 0; i < n; i++) {
            if(st.count(vs[i]) == 0) {
                unique++;
                st.insert(vs[i]);
            }
        }
        st.clear();
        for (int i = 0; i < (n-1); i++) {
            string str1 = vs[i];
            for (int j = (i+1); j < n; j++) {
                string str2 = vs[j];
                if(str1.compare(str2) != 0 and my_hash(str1) == my_hash(str2))
                    collisions++;
            }
        }
        cout << unique << " " << collisions << endl;
    }
    return 0;
}