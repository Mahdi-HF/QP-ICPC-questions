#include <bits/stdc++.h>
using namespace std;
#define INF (INT32_MAX - 100)
#define SIZE 100000005

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n ,m;
    cin >> n >> m;
    bool arr[n+5];
    for (int i = 0; i < n+5; i++)
        arr[i] = 0;

    for (int i = 0; i < m; i++){
        int op, s, e;
        cin >> op >> s >> e;
        s = s-1;
        e = e-1;
        int res = 0;
        if(op==0){
            for (int j = s; j <= e; j++){
                arr[j] = !arr[j];
            }
        }
        else if(op == 1){
            for (int j = s; j <= e; j++){
                if(arr[j] == 1)
                    res++;
            }
            cout << res << endl;
        }
    }


    return 0;
}