#include <bits/stdc++.h>
using namespace std;
#define SIZE  100000005
#define SIZE2 100000000
#define int long long

int aa[SIZE];
int bb[SIZE];

int32_t main(){
    while(1)
    {
        int lenA=0, lenB=0;
        int minI=0, minJ=0;

        cin>>aa[0]>>bb[0];
        if(aa[0] == 0 and bb[0] == 0)
            break;
        for(int i=0;i<SIZE2;i++)
        {
            if(aa[i] == 1)
            {
                lenA = i+1;
                break;
            }
            if(aa[i] == 2)
            {
                aa[i+1]=1;
                lenA = i+2;
                break;
            }
            if(aa[i] % 2 == 0)
                aa[i+1] = aa[i]/2;
            else
                aa[i+1] = (3 * aa[i]) + 1;
        }
        for(int i=0;i<SIZE2;i++)
        {
            if(bb[i] == 1)
            {
                lenB = i+1;
                break;
            }
            if(bb[i] == 2)
            {
                bb[i+1]=1;
                lenB = i+2;
                break;
            }
            if(bb[i] % 2 == 0)
                bb[i+1] = bb[i]/2;
            else
                bb[i+1] = (3 * bb[i]) + 1;
        }
        int k=0;
        for(int i=0;i<lenA;i++)
        {
            if(k==1) break;
            for(int j=0;j<lenB;j++)
            {
                if(aa[i] == bb[j])
                {
                    minI = i;
                    minJ = j;
                    k=1;
                    break;
                }
            }
        }
        // for(int i=0;i<lenA;i++)
        // {
        //     cout << " "<< aa[i];
        // }
        // cout << endl;
        // for(int j=0;j<lenB;j++)
        // {
        //     cout << " "<< bb[j];
        // }
        // cout << endl;
        cout << aa[0] << " needs " << minI << " steps, ";
        cout << bb[0] << " needs " << minJ << " steps, they meet at ";
        cout << aa[minI] << endl;

    }
    return 0;
}