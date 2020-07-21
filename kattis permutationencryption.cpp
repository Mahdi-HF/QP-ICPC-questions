#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1)
    {
        int arr[22];
        int n;
        string str, encrypted;
        for(int i=0;i<21;i++)
            arr[i]=0;
        cin>>n;
        if(n == 0)
            break;
        for(int i=0;i<n;i++)
            cin >> arr[i];
        char c;
        cin >> c;
        if(!isdigit(c))
        {
            getline(cin, str);
            str = c + str;
        }
        else
        {
            cout << "'" << "" << "'" << endl;
            n = c - '0';
            if(n == 0)
                break;
            for(int i=0;i<n;i++)
                cin >> arr[i];
            char c;
            cin >> c;
            getline(cin, str);
            str = c + str;
        }
        // 2 problem: if the first number is 2 digit!
        // and if 2 empty become after each other
        int len = 0;
        int strlen = str.length();
        while(1)
        {
            if(len<strlen)
                len += n;
            else break;
        }
        int phase = 0;
        for(int i=1;i<=len;i++)
        {
            if(n == 1)
            {
                cout << "'" << str << "'" << endl;
                break;
            }
            int in = (i%n) - 1;
            if(in == -1)
                in = (n-1);
            int num = arr[in];
            int inx = num+(n*phase)-1;
            char cc = str[inx];
            if(strlen<=inx)
                encrypted.push_back(' ');
            else encrypted.push_back(cc);
            if(i%n == 0)
                phase++;
            // cout<<i<<" -> "<< num <<"  "<< inx <<"   "<< cc <<"   "<< phase << endl;
        }
        if(n != 1) cout << "'" << encrypted << "'" << endl;
    }

    return 0;
}