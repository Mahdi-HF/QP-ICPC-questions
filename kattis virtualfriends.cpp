#include<bits/stdc++.h>
using namespace std;

class DisjSet{ 
    int *rank, *parent, n, *num; 
  
public:
    DisjSet(int n){ 
        rank = new int[n]; 
        parent = new int[n]; 
        num = new int[n];
        this->n = n; 
        makeSet(); 
    } 
    void makeSet(){ 
        for (int i = 0; i < n; i++){ 
            parent[i] = i;
            num[i] = 1; 
        } 
    } 
    int find(int x){ 
        if (parent[x] != x){ 
            parent[x] = find(parent[x]); 
        } 
        return parent[x]; 
    } 
    int Union(int x, int y){ 
        int xset = find(x); 
        int yset = find(y); 
        if (xset == yset) 
            return num[xset]; 
        if (rank[xset] < rank[yset]){ 
            parent[xset] = yset;
            num[yset] += num[xset];
            return num[yset];
        } 
        else if (rank[xset] > rank[yset]){ 
            parent[yset] = xset; 
            num[xset] += num[yset];
            return num[xset];
        } 
        else{ 
            parent[yset] = xset; 
            rank[xset] = rank[xset] + 1;
            num[xset] += num[yset];
            return num[xset];
        }
    } 
};

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        DisjSet network(2 * n + 1);
        map<string, int> mp;
        int ind = 0;
        for (int j = 0; j < n; j++){
            string str1, str2;
            cin >> str1 >> str2;
            int ind1 = 0;
            if (mp.find(str1) == mp.end()){
                mp.insert(make_pair(str1, ind));
                ind1 = ind;
                ind++;
            }
            else ind1 = mp.find(str1)->second;

            int ind2 = 0;
            if (mp.find(str2) == mp.end()){
                mp.insert(make_pair(str2, ind));
                ind2 = ind;
                ind++;
            }
            else ind2 = mp.find(str2)->second;
            int res = network.Union(ind1, ind2);
            cout << res << endl;
        }
    }
    return 0;
}