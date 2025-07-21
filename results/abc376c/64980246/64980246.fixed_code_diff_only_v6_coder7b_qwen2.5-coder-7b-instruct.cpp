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
    
    // Sort toys in ascending order
    sort(a.begin(), a.end());
    // Sort boxes in descending order
    sort(b.rbegin(), b.rend());

    int x = -1;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        // Check if the current toy can fit into any remaining box
        if (j < n - 1 && a[i] <= b[j]) {
            ++j;
        } else {
            // If we cannot place the current toy in any box, we need a new box
            x = a[i];
            break;
        }
    }

    cout << x << endl;
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