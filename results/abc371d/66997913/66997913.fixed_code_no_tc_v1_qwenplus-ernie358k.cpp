#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end()); // Sort x to use binary search correctly

    vector<ll> p(n), s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s[i + 1] = s[i] + p[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // Use binary search to find the correct indices in the sorted x array
        auto it_r = upper_bound(x.begin(), x.end(), r);
        auto it_l = lower_bound(x.begin(), x.end(), l);
        
        // Calculate the indices in the original array (0-based adjusted)
        int rt = it_r - x.begin();
        int lt = it_l - x.begin();
        
        // Since we are summing prefix sums, we need to adjust the left index properly
        // If the left index points to an element not greater than or equal to 'l', we decrement it
        // But since we're using 0-based indexing and prefix sums start from 0, we don't need to adjust further
        // Just ensure we don't go out of bounds (i.e., lt should be at least 0)
        lt = max(0, lt - 1);
        
        // Now calculate the sum using prefix sums
        ll ans = s[rt] - s[lt];
        cout << ans << endl;
    }
    return 0;
}