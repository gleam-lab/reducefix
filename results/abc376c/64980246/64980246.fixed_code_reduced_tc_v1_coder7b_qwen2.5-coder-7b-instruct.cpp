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

    // Initialize variables
    int x = -1;
    bool found = false;

    // Iterate through the sorted boxes
    for (int i = 0; i < n - 1; ++i) {
        // Check if the current toy can fit in the current box
        if (a[0] <= b[i]) {
            x = b[i];
            found = true;
            break;
        }
    }

    // If no suitable box was found, check if any toy can fit in a new box
    if (!found) {
        x = a[n - 1];
    }

    // Output the result
    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}