#include <bits/stdc++.h>
using namespace std;
// #define INF INT32_MAX - 100
#define SIZE 100000005
#define int long long

int arr[SIZE];
int res = 0;

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 and j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            res += n1 - i;
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    str.clear();
    getline(cin,str);
    int n = str.length();

    for (int i = 0; i < n; i++){
        arr[i] = (int)str[i] - 48 + 5;
        // cout << arr[i] << " ";
    }
    
    mergeSort(arr, 0, n-1);
    // cout << endl;
    cout << res << endl;

    return 0;
}