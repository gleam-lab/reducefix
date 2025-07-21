#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    unordered_set<int> s;
    map<int, int> freq;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            if (freq[x] == 0)
                s.insert(x);
            freq[x]++;
        }
        else if (a == 2)
        {
            int y;
            cin >> y;
            freq[y]--;
            if (freq[y] == 0)
                s.erase(y);
        }
        else if (a == 3)
        {
            cout << s.size() << endl;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}