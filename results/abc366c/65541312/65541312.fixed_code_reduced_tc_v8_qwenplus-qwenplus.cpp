#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    multiset<int> ms;  // Use multiset to allow duplicate values and efficient operations
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            ms.insert(x);
        }
        else if (a == 2)
        {
            int y;
            cin >> y;
            auto it = ms.find(y);
            if (it != ms.end()) {
                ms.erase(it);  // Remove one occurrence
            }
        }
        else if (a == 3)
        {
            // Use a set to count distinct elements
            set<int> distinct_elements(ms.begin(), ms.end());
            cout << distinct_elements.size() << endl;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}