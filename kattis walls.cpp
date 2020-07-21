#include <bits/stdc++.h>
using namespace std;

// bool flagA = 0, flagB = 0, flagC = 0, flagD = 0;
set < pair <double, double> > aa, bb, cc, dd;
// multiset<pair<double, double>> all;
// long long count_of_lifts = 0;

bool distance(pair<double, double> p1, pair<double, double> p2, double r){
    double one = abs(p1.first - p2.first);
    double two = abs(p1.second - p2.second);
    double res = pow(one, 2) + pow(two, 2);
    double r2 = pow(r, 2);
    if (res <= r2)
        return true;
    else
        return false;
}

// void fill_all(){
//     all.clear();
//     if(!flagA){
//         for (auto elm : aa)
//             all.insert(elm);
//     }
//     if (!flagB){
//         for (auto elm : bb)
//             all.insert(elm);
//     }
//     if (!flagC){
//         for (auto elm : cc)
//             all.insert(elm);
//     }
//     if (!flagD){
//         for (auto elm : dd)
//             all.insert(elm);
//     }
// }

// pair<double, double> find_max(){
//     pair<double, double> max_point = make_pair(0, 0);
//     int max_num = 0;
//     for (auto it = all.begin(); it != all.end(); it++){
//         int num = all.count(*it);
//         if (num > max_num){
//             max_point = *it;
//             max_num = num;
//         }
//     }
//     return max_point;
// }

// void check_sets(pair<double, double> max_point){
//     int sum1 = flagA + flagB + flagC + flagD;
//     if (aa.find(max_point) != aa.end() and !flagA)
//         flagA = 1;
//     if (aa.find(max_point) != bb.end() and !flagB)
//         flagB = 1;
//     if (aa.find(max_point) != cc.end() and !flagC)
//         flagC = 1;
//     if (aa.find(max_point) != dd.end() and !flagD)
//         flagD = 1;
//     int sum2 = flagA + flagB + flagC + flagD;
//     if(sum2-sum1 > 0)
//         count_of_lifts++;
// }

// bool is_finish(){
//     if (flagA & flagB & flagC & flagD == 1)
//         return true;
//     else return false;
// }

// void try2(){
//     fill_all();
//     pair<double, double> max_point = find_max();
//     // cout << max_point.first << " " << max_point.second << endl;
//     check_sets(max_point);
//     if (is_finish() == true)
//         cout << count_of_lifts << endl;
//     else {
//         try2();
//     }
// }

vector<int> reach[32];
int ans = 4;

int main(){
    double l, w, r;
    int n;
    cin>>l>>w>>n>>r;
    pair<double, double> a = make_pair(0, -w / 2), b = make_pair(l / 2, 0);
    pair<double, double> c = make_pair(0, w / 2), d = make_pair(-l / 2, 0);
    vector<pair<double, double>> pnts;
    for (int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        pair<double, double> point = make_pair(x, y);
        pnts.push_back(point);
        if (distance(point, a, r))
            aa.insert(point);
        if (distance(point, b, r))
            bb.insert(point);
        if (distance(point, c, r))
            cc.insert(point);
        if (distance(point, d, r))
            dd.insert(point);
    }
    // cout << aa.size() << " " << bb.size() << " " << cc.size() << " " << dd.size() << " " << endl;
    if(aa.empty() or bb.empty() or cc.empty() or dd.empty()){
        cout << "Impossible";
        return 0;
    }
    // else try2();
    else {
        int i=0;
        for(auto it = pnts.begin(); it != pnts.end(); it++, i++) {
            if(binary_search(aa.begin(), aa.end(), *it)) reach[i].push_back(0);
            if(binary_search(bb.begin(), bb.end(), *it)) reach[i].push_back(1);
            if(binary_search(cc.begin(), cc.end(), *it)) reach[i].push_back(2);
            if(binary_search(dd.begin(), dd.end(), *it)) reach[i].push_back(3);
        }
        set<int> temp;
        for(int i = 0; i < n; i++) {
            if(reach[i].size() == 4) ans = min(ans, 1);
            
            for(int j = 0; j < n; j++) {
                temp.clear();
                for(auto it: reach[i]) temp.insert(it);
                for(auto it: reach[j]) temp.insert(it);
                if(temp.size() == 4) ans = min(ans, 2);

                for(int k = 0; k < n; k++) {
                    temp.clear();
                    for(auto it: reach[i]) temp.insert(it);
                    for(auto it: reach[j]) temp.insert(it);
                    for(auto it: reach[k]) temp.insert(it);
                    if(temp.size() == 4) ans = min(ans, 3);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}