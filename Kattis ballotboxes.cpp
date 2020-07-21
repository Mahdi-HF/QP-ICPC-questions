#include <bits/stdc++.h>
using namespace std;

struct City
{
    int pop, count;
};

bool operator<(const City &c1, const City &c2)
{
    return c1.pop / (double)c1.count < c2.pop / (double)c2.count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        int n, b;
        priority_queue<City> pq;
        scanf("%d %d", &n, &b); // cin >> n >> b;
        if (n == -1)
            break;
        for (int i = 0; i < n; i++)
        {
            int p;
            scanf("%d", &p); // cin >> num;
            City tmp = City();
            tmp.pop = p;
            tmp.count = 1;
            pq.push(tmp);
        }
        b -= n;
        while (b--)
        {
            City tmp = pq.top();
            pq.pop();
            tmp.count += 1;
            pq.push(tmp);
        }

        City ans = pq.top();
        double value = ans.pop / (double)ans.count;
        int value_rond = (int)value;
        if (value != value_rond)
            cout << value_rond + 1 << endl;
        else
            cout << value_rond << endl;
    }
    return 0;
}