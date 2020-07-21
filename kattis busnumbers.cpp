#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    while(cin>>n)
    {
        int arr[1005];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        sort(arr, arr+n);

        int start = arr[0];
        int finish;
        bool isMore;
        for(int i=1;i<=n;i++)
        {
            if(arr[i] == arr[i-1]+1)
            {
                finish = arr[i];
                isMore = 1;
            }
            else if(isMore)
            {
                if(finish - start == 1)
                    cout << start << " " << finish << " ";
                else
                    cout << start << "-" << finish << " ";
                start = arr[i];
                isMore = 0;
            }
            else
            {
                cout << start << " ";
                start = arr[i];
            }
            if(i == n)
                cout << endl;
        }
    }
    
    return 0;
}