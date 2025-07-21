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
    
    // The maximum size among the toys and the existing boxes
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int max_size = max(a[0], b[0]);
    
    // Find the smallest box size needed
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > b[i])
        {
            cout << a[i] << endl;
            return;
        }
        max_size = max(max_size, b[i]);
    }
    
    // If all toys fit in the existing boxes
    if (a.back() <= max_size)
    {
        cout << -1 << endl;
        return;
    }
    
    // If all toys do not fit and we need a new box
    cout << max_size + 1 << endl;
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