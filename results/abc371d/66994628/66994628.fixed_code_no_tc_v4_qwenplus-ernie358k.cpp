#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1), sum(n + 1, 0);

    // Read the x values (0-based index for simplicity, though not used directly)
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    // Read the p values and compute prefix sum
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        // Convert l and r to 0-based indices for binary search
        auto it_l = lower_bound(x.begin() + 1, x.end(), l) - x.begin();
        auto it_r = upper_bound(x.begin() + 1, x.end(), r) - x.begin();

        // Adjust for 1-based indexing in output (since p and sum are 1-based effectively)
        // Note: it_l and it_r are 0-based indices for x, but we need 1-based for sum
        cout << sum[it_r - 1] - sum[it_l - 1] << endl;
    }

    return 0;
}