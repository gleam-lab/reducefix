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

    // Initialize variables to track the minimum box size needed
    int x = -1;
    int j = 0;

    // Iterate through the toys
    for (int i = 0; i < n; ++i) {
        // Find a suitable box for the current toy
        while (j < n - 1 && b[j] < a[i]) {
            ++j;
        }
        
        // If we found a suitable box, check its size
        if (j < n - 1 && b[j] >= a[i]) {
            if (x == -1) {
                x = b[j];
            } else {
                x = max(x, b[j]);
            }
        } else {
            // If no suitable box was found, break the loop
            break;
        }
    }

    // Output the result
    if (x != -1) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // Uncomment the line below to read multiple test cases
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}