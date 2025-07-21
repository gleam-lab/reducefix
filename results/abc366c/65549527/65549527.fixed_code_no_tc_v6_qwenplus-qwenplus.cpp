#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    unordered_map<int, int> countMap; // Tracks count of each number in the bag
    set<int> uniqueSet;               // Tracks currently present unique integers

    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            countMap[x]++;
            if (countMap[x] == 1)
            {
                uniqueSet.insert(x);
            }
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0)
            {
                uniqueSet.erase(x);
            }
        }
        else if (type == 3)
        {
            cout << uniqueSet.size() << endl;
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