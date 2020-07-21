#include <bits/stdc++.h>
using namespace std;

string path;
int arr[1006][1006];

int main(){
    for(int i=0;i<1005;i++)
    {
        for(int j=0;j<1005;j++)
        {
            arr[i][j] = 0;
        }
    }
    int i1 = 502;
    int j1 = 502;
    int bottom, left, right, top;
    arr[i1][j1] = 8;
    while(getline(cin, path))
    {
        if(path.compare("down") == 0)
            i1++;
        else if(path.compare("up") == 0)
            i1--;
        else if(path.compare("left") == 0)
            j1--;
        else if(path.compare("right") == 0)
            j1++;
        if(arr[i1][j1] != 8)
            arr[i1][j1] = 1;
    }
    arr[i1][j1] = 9;
    for(int i=0;i<1005;i++)
    {
        for(int j=0;j<1005;j++)
        {
            if(arr[i][j] == 1 or arr[i][j] == 8 or arr[i][j] == 9)
                bottom = i;
        }
    }
    // cout << "fuck very first " << endl;
    for(int i=0;i<1005;i++)
    {
        for(int j=0;j<1005;j++)
        {
            if(arr[j][i] == 1 or arr[j][i] == 8 or arr[j][i] == 9)
                right = i;
        }
    }
    // cout << "fuck first " << endl;
    for(int i=1004;i>=0;i--)
    {
        for(int j=1004;j>=0;j--)
        {
            if(arr[i][j] == 1 or arr[i][j] == 8 or arr[i][j] == 9)
                top = i;
        }
    }
    // cout << "fuck late first " << endl;
    for(int i=1004;i>=0;i--)
    {
        for(int j=1004;j>=0;j--)
        {
            if(arr[j][i] == 1 or arr[j][i] == 8 or arr[j][i] == 9)
                left = i;
        }
    }
    // cout << top << " - " << bottom << "  /  " << right << " - " << left  << endl;
    int hei = bottom - top + 1;
    int len = right - left + 3;
    for(int j=0;j<len;j++) // #######
        cout<<'#';
    cout<<endl;
    int ii = top;
    for(int i=0;i<hei;i++)
    {
        int jj = left;
        cout<<'#';
        for(int j=0;j<(len-2);j++) // # 12345678 #
        {
            if(arr[ii][jj] == 1)
                cout << '*';
            else if(arr[ii][jj] == 8)
                cout << 'S';
            else if(arr[ii][jj] == 9)
                cout << 'E';
            else
                cout << ' ';
            jj++;
        }
        ii++;
        cout<<'#'<<endl;
    }
    for(int j=0;j<len;j++) // #######
        cout<<'#';
    cout<<endl;

    return 0;
}