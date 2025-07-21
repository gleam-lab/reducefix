#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    
    unordered_map<int, int> countMap; // Tracks count of each number in the bag
    int uniqueCount = 0;              // Number of distinct integers in the bag

    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            if (countMap[x] == 0)
                uniqueCount++;
            countMap[x]++;
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0)
                uniqueCount--;
        }
        else if (type == 3)
        {
            cout << uniqueCount << endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}