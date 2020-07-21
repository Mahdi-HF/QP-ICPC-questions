#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str;
    for(int ii=0;ii<n;ii++)
    {
        cin >> str;
        int len = str.length();
        int pw = 1;
        while(1)
        {
            if(pw < sqrt(len))
                pw++;
            else break;
        }
        char arr[pw][pw];
        int k=0;

        for(int i=0;i<pw;i++)
        {
            for(int j=0;j<pw;j++)
            {
                arr[i][j] = '*';
            }
        }

        for(int i=0;i<pw;i++)
        {
            if(k == len) break;
            for(int j=0;j<pw;j++)
            {
                if(k == len) break;
                arr[i][j] = str[k];
                k++;
            }
        }

        for(int j=0;j<pw;j++)
        {
            for(int i=(pw-1);i>=0;i--)
            {
                char cc = arr[i][j];
                if(cc != '*')
                    cout << cc;
            }
        }
        cout << endl;
    }

    return 0;
}