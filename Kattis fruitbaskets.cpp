#include <bits/stdc++.h>
using namespace std;
#define int long long

int Less_than_200(vector<int> arr, int is_inc, int the_one, int weight){
    if (the_one == arr.size() or is_inc == 4){
        if(weight < 200)
            return weight;
        else return 0;
    }
    int ans = Less_than_200(arr, is_inc + 1, the_one + 1, weight + arr[the_one]);
    ans += Less_than_200(arr, is_inc, the_one + 1, weight);
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    sum = sum * pow(2, n - 1);

    int sum2 = 0;
    sum2 = Less_than_200(arr, 0, 0, 0);
    cout << sum - sum2 << endl;
    return 0;
}