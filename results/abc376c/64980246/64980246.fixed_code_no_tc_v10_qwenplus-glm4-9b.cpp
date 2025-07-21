#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> b[i];
    
    // Sort both arrays in descending order
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    // Map box sizes to their indices for faster lookup
    map<int, int> box_map;
    for (int i = 0; i < n - 1; ++i)
        box_map[b[i]] = i;

    // Try to place each toy in the largest possible box starting from the largest toy
    int x = 0; // This will store the size of the box we need to buy
    for (int i = 0; i < n; ++i)
    {
        // If the toy can fit in an existing box, find the largest box that can fit it
        if (box_map.lower_bound(a[i]) != box_map.end())
        {
            x = max(x, box_map.begin()->first); // Update x to the largest box we can use
        }
        else
        {
            // If we cannot fit the current toy in any existing box, we need to buy a new box
            x = max(x, a[i]);
        }
    }
    
    // If we never set x, it means we never needed a new box, so x remains 0
    // If x is 0, it means we can use the existing boxes only, so we need a box of size 1
    if (x > 0 || (n >= 2 && a[0] > b[0]))
        cout << x << endl;
    else
        cout << -1 << endl;
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