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
    
    // Sort both arrays in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int x = -1;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        // Check if we can place toy i into any of the available boxes
        if (j < n - 1 && a[i] <= b[j]) {
            ++j; // Move to the next box
        } else {
            // If we cannot place toy i into the current or any future box
            // We need to buy a new box with size at least a[i]
            if (x == -1 || a[i] > x) {
                x = a[i];
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}