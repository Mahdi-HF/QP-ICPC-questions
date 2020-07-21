#include <bits/stdc++.h>
using namespace std;
#define int long long

class BIT{
private:
    vector<int> m_array;
    int n;

public:
    BIT(int n){
        this->n = n;
        m_array.assign(n + 1, 0);
    }

    int prefix_query(int idx) const{
        int result = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            result += m_array[idx];
        return result;
    }

    void update(int idx, int add){
        for (++idx; idx < m_array.size(); idx += idx & -idx)
            m_array[idx] += add;
    }
};

int32_t main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int movie, req;
        cin >> movie >> req;
        vector<int> array(movie+5);
        BIT fenwick(200005);
        fenwick.update(1, movie);
        int bb = movie + 1;
        for (int j = 0; j < movie; j++){
            fenwick.update(j+2, -1);
            array[j+1] = bb - j;
        }
        for (int j = 0; j < req; j++){
            int aa, ans=0;
            cin >> aa;
            bb++;
            ans = fenwick.prefix_query(array[aa]);
            fenwick.update(array[aa], 1);
            fenwick.update(bb, -1);
            array[aa] = bb;
            if (j != req - 1)
                cout << ans << " ";
            else
                cout << ans << endl;
        }
    }
    return 0;
}
