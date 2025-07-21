#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i)
    {
        cin >> b[i];
    }
    
    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize variables
    ll max_size = *max_element(a.begin(), a.end()); // Maximum toy size
    ll min_box_size = *min_element(b.begin(), b.end()); // Minimum box size
    bool can_fit = true;

    // Check if we can fit all toys using the smallest possible box
    for (ll i = 0; i < n - 1; ++i)
    {
        if (b[i] < a[i]) // If current box cannot hold the current toy
        {
            can_fit = false;
            break;
        }
    }

    // If we can't fit all toys with the existing boxes, check if a new box is needed
    if (!can_fit)
    {
        for (ll i = 0; i < n - 1; ++i)
        {
            if (b[i] < a[i] && b[i] >= max_size) // If current box can hold the maximum toy but smaller than the current toy
            {
                b[i] = max_size; // Upgrade this box
                break;
            }
        }
        if (b[n - 2] < max_size) // If the last box still cannot hold the maximum toy
        {
            cout << -1 << endl; // Cannot fit all toys
            return;
        }
    }

    // Find the smallest box that can hold all toys
    for (ll i = 0; i < n - 1; ++i)
    {
        if (b[i] >= max_size)
        {
            cout << b[i] << endl;
            return;
        }
    }
}

int main()
{
    solve();
}