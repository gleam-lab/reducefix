#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    ll x = -1;
    for (int i = 0, j = 0; i < n && j < n - 1; ++i)
    {
        if (a[i] <= b[j])
        {
            if (x == -1)
                x = b[j];
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        else
            ++j;
    }
    cout << x << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}