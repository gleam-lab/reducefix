#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // We will use a pointer approach to match toys to boxes
    int i = 0, j = 0;
    int x = -1;

    while (i < n && j < n - 1)
    {
        if (a[i] <= b[j])
        {
            ++i;
            ++j;
        }
        else
        {
            // This toy needs the extra box
            if (x == -1)
                x = a[i];
            else
            {
                // Two toys can't be fit in one extra box
                cout << -1 << endl;
                return;
            }
            ++i;
        }
    }

    // After loop, if there is a remaining toy, it must go into the extra box
    if (i < n)
    {
        if (x == -1)
            x = a[i];
        else
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << x << endl;
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