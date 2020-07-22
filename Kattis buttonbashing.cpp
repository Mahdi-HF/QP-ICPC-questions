#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 3605
#define INF 4000
#define int long long

vector<int> vec;
int arr[SIZE];

int32_t main(){
    FAST
    int tc; cin >> tc;
    for (int i = 0; i < tc; i++){

        vec.clear();
        arr[0] = 0;
        for (int j = 1; j < 3601; j++)
            arr[j]=INF;

        int n, time;
        cin >> n >> time;
        for (int j = 0; j < n; j++){
            int num; cin >> num;
            vec.push_back(num);
        }

        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto elm : vec) {
                int next = curr + elm;
                if(next < 0)
                    next = 0;
                if(next > 3600)
                    next = 3600;

                if(arr[next] > arr[curr]+1) {
                    arr[next] = arr[curr] + 1;
                    q.push(next);
                }
            }
        }

        for (int j = time; j <= 3600; j++){
            if(arr[j] != INF){
                cout << arr[j] << " " << j-time << endl;
                break;
            }
        }
    }

    return 0;
}