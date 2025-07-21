#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int n, q;
vector<int> a(N);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        int lb = lower_bound(a.begin(), a.end(), b) - a.begin();
        int ub = upper_bound(a.begin(), a.end(), b) - a.begin();
        // Adjust k to be zero-indexed
        int k_idx = k - 1;
        // Find the k-th closest distance
        int ans = abs(a[lb + k_idx] - b);
        if (lb + k_idx >= k) {
            ans = min(ans, abs(a[lb + k_idx - 1] - b));
        }
        if (ub - k_idx > n - k) {
            ans = min(ans, abs(a[ub + k_idx] - b));
        }
        cout << ans << "\n";
    }

    return 0;
}