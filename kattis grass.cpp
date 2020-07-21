#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    double l, w;
    while (cin >> n >> l >> w){
        vector <pair<double, double>> vec;
        int cnt = 0;
        bool printed = 0;
        double till_here = 0;
        double w2 = w / 2;
        double w22 = w2 * w2;
        for (int i = 0; i < n; i++){
            int x, r;
            cin >> x >> r;
            if(r <= w2) continue;
            double r2 = r * r;
            double fisaghures = r2 - w22;
            double x1 = sqrt(fisaghures);
            double beg = x - x1, fin = x + x1;
            vec.push_back({beg, fin});
        }
        while (till_here <= l){
            pair<double, double> max_pr = {0,0};
            auto max_pr_it = vec.begin();
            double max_pr_len = 0;
            bool found = 0;
            for (auto it = vec.begin(); it != vec.end(); it++){
                auto pr = *it;
                double start = pr.first, finish = pr.second;
                double len = finish - till_here;
                if(max_pr_len < len and till_here < finish and till_here > start){
                    found = 1;
                    max_pr = pr;
                    max_pr_it = it;
                    max_pr_len = len;
                }
            }
            if(!found){
                cout << "-1" << endl;
                printed = 1;
                break;
            }
            till_here = max_pr.second;
            vec.erase(max_pr_it);
            cnt++;
        }
        if(!printed) cout << cnt << endl;
        vec.clear();
    }
    return 0;
}