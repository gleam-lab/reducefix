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
    
    // Initialize the minimum box size needed
    int minBoxSize = -1;
    
    // Iterate through the toys and boxes
    for (int i = 0, j = 0; i < n && j < n - 1;) {
        if (a[i] <= b[j]) {
            // If the current toy fits in the current box, move to the next toy
            ++i;
        } else {
            // If the current toy does not fit in the current box, increase the box size
            if (minBoxSize == -1 || b[j] >= minBoxSize) {
                minBoxSize = b[j] + 1;
                ++j;
            } else {
                // If we cannot find a suitable box, break and output -1
                minBoxSize = -1;
                break;
            }
        }
    }
    
    // Output the result
    cout << minBoxSize << endl;
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