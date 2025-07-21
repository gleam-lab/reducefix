#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    
    // Sort toys and boxes in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Initialize the minimum box size needed
    int x = -1;
    
    // Iterate through toys and boxes
    for (int i = 0, j = 0; i < n && j < n - 1; ++i) {
        if (a[i] <= b[j]) {
            ++j; // Move to the next box if the current toy fits
        } else {
            // If the current toy doesn't fit in any remaining box, we need a new box
            if (x == -1)
                x = a[i]; // Set the minimum box size needed
            else {
                cout << -1 << endl; // It's impossible to place all toys
                return;
            }
        }
    }
    
    // Check if all toys fit with the minimum box size
    if (x != -1 && a[n - 1] > x) {
        cout << -1 << endl; // It's impossible to place all toys
        return;
    }
    
    cout << x << endl; // Print the minimum box size needed
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}