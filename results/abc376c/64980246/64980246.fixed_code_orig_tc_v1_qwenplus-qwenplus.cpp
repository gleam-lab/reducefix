#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    multiset<ll> boxes;
    int j = 0;
    ll res = -1;

    for (int i = 0; i < n; ++i)
    {
        // Add all boxes smaller than or equal to current toy size
        while (j < n - 1 && b[j] < a[i])
        {
            boxes.insert(b[j]);
            j++;
        }

        if (!boxes.empty())
        {
            // Try to find the smallest box that can fit this toy
            auto it = boxes.lower_bound(a[i]);
            if (it != boxes.end())
            {
                // Found a suitable box, remove it
                boxes.erase(it);
            }
            else
            {
                // No suitable box found yet, we need to add an extra box
                res = a[i];
                break;
            }
        }
        else
        {
            // No boxes left to assign, need to add an extra box
            res = a[i];
            break;
        }
    }

    cout << res << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}