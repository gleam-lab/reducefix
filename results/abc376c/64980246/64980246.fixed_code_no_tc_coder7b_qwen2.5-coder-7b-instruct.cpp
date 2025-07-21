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
    int x = -1;
    for (int i = 0, j = 0; i < n; ++i)
    {
        if (j < n - 1 && a[i] <= b[j])
            ++j;
        else
        {
            if (x == -1)
                x = a[i];
            else
            {
                cout << -1 << endl;
                return;
            }
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