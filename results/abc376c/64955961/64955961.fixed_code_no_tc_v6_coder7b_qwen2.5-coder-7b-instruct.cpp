//<<In the name of Allah, The Most Gracious and The Most Merciful>>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize variables
    ll min_box_size = INT_MAX;
    bool possible = true;

    // Iterate through the toys and boxes
    for (ll i = 0, j = 0; i < n && j < n - 1;) {
        if (a[i] <= b[j]) {
            i++;
        } else {
            // If current toy cannot fit into the current box, increase the box size
            min_box_size = max(min_box_size, b[j]);
            j++;
            possible = false;
        }
    }

    // Check if we have enough boxes with the required size
    if (!possible || (j == n - 1 && i != n)) {
        cout << -1 << endl;
    } else {
        cout << min_box_size << endl;
    }
}

int main() {
    solve();
    return 0;
}