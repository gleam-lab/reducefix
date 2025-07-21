#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<ll> maxLeft(n), maxRight(n);

    // maxLeft[i] is the maximum sum of a subarray ending at index i
    ll currentMax = 0;
    for (int i = 0; i < n; ++i) {
        currentMax = max((ll)(i > 0 ? maxLeft[i - 1] : 0) + v[i], currentMax);
        maxLeft[i] = currentMax;
    }

    // maxRight[i] is the maximum sum of a subarray starting at index i
    currentMax = 0;
    for (int i = n - 1; i >= 0; --i) {
        currentMax = max((ll)(i < n - 1 ? maxRight[i + 1] : 0) + v[i], currentMax);
        maxRight[i] = currentMax;
    }

    // Find the maximum sum of two non-overlapping subarrays
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, maxLeft[i] + maxRight[i + 1]);
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}