#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    unordered_map<int, int> freq; // To keep track of counts of each number
    int distinct = 0;             // To store current number of distinct integers

    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            if (freq[x] == 0)
                ++distinct;
            ++freq[x];
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            --freq[x];
            if (freq[x] == 0)
                --distinct;
        }
        else // type == 3
        {
            cout << distinct << endl;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}