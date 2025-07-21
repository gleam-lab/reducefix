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

    if (b[0] >= a[0]) {
        cout << "-1" << endl;
        return;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        if (b[i] >= a[i + 1])
        {
            cout << a[i + 1] << endl;
            return;
        }
    }

    cout << a.back() << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}