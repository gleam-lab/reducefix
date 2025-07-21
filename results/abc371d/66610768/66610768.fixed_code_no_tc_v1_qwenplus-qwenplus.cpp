#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<ll> prefix_b(n + 1, 0); // Use prefix sum for b

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        int b_val;
        cin >> b_val;
        prefix_b[i] = prefix_b[i - 1] + b_val;
    }

    // Ensure a is sorted for binary search
    // As per the logic, it seems input a should be non-decreasing
    // If not, we need to sort them along with corresponding b values
    // Assuming a is already in non-decreasing order

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        // Find first index where a[i] >= l
        int left = lower_bound(a.begin() + 1, a.end(), l) - a.begin();

        // Find last index where a[i] <= r
        int right = upper_bound(a.begin() + 1, a.end(), r) - a.begin() - 1;

        if (left > right) {
            cout << 0 << "\n";
        } else {
            cout << prefix_b[right] - prefix_b[left - 1] << "\n";
        }
    }

    return 0;
}