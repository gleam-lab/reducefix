#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

ll solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int &val : a)
        cin >> val;
    for (int &val : b)
        cin >> val;
    
    // Sort the toy sizes in ascending order
    sort(a.begin(), a.end());
    // Sort the existing box sizes in descending order
    sort(b.begin(), b.end(), greater<int>());

    ll x = 0;
    for (int i = 0; i < n; ++i) {
        // Check if the current toy can fit in the current box
        bool canFit = false;
        for (int j = 0; j < n - 1; ++j) {
            if (a[i] <= b[j]) {
                canFit = true;
                break;
            }
        }
        // If not all toys can fit, return -1
        if (!canFit) {
            cout << -1 << endl;
            return -1;
        }
        // Update x to the largest box size used
        x = max(x, b[n - 2 - i]);
    }
    cout << x << endl;
    return x;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}