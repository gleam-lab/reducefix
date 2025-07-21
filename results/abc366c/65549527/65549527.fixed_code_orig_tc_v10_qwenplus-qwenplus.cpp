#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    
    // We need to track the count of each number to handle duplicates correctly
    map<int, int> freq;
    set<int> distinct;

    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            if (freq[x] == 0)
                distinct.insert(x);
            freq[x]++;
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0)
                distinct.erase(x);
        }
        else if (type == 3)
        {
            cout << distinct.size() << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
}