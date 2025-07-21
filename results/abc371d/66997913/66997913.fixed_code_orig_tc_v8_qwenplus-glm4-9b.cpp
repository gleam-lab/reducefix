#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    
    vector<ll> prefix_sums(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sums[i + 1] = prefix_sums[i] + x[i];
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // Ensure l is not greater than r
        if (l > r) swap(l, r);
        // Adjust l to start from the beginning of the array
        l += 1;  // This is needed because 0-based index
        // Find the difference of prefix sums
        ll sum = prefix_sums[r] - prefix_sums[l];
        cout << sum << endl;
    }
    return 0;
}