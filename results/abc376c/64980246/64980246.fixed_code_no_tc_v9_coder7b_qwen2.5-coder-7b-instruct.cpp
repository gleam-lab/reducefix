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
    
    // Sort the sizes of toys and boxes in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int x = -1;
    for (int i = 0, j = 0; i < n && j < n - 1; ++i)
    {
        if (a[i] <= b[j])
        {
            if (x == -1)
                x = b[j]; // The smallest box that can hold toy i
            else
            {
                x = max(x, b[j]); // Ensure we have a box big enough for any toy
            }
            ++j;
        }
        // If current toy cannot fit in current box, move to next box
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