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
    
    // Sort both arrays in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize the minimum box size needed
    int min_box_size = -1;

    // Iterate through the sorted toys and boxes
    for (int i = 0, j = 0; i < n && j < n - 1; ++i)
    {
        if (a[i] <= b[j])
        {
            // If current toy can fit in the current box, move to the next toy
            ++j;
        }
        else
        {
            // If current toy cannot fit in the current box, check if we need a new box
            if (min_box_size == -1)
                min_box_size = a[i];
            else
            {
                // If we already have a minimum box size, it means we cannot fit all toys
                cout << -1 << endl;
                return;
            }
        }
    }

    // If we successfully placed all toys, print the minimum box size
    if (min_box_size != -1)
        cout << min_box_size << endl;
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