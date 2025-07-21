#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
long long sum[200005];  // Use prefix sums instead of map for better performance

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];  // Compute prefix sums correctly
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        // Find the first index where x[i] >= L
        int left = lower_bound(x + 1, x + n + 1, L) - x;

        // Find the first index where x[i] > R
        int right = upper_bound(x + 1, x + n + 1, R) - x;

        // All elements from 'left' to 'right-1' are in range [L, R]
        if (left <= right - 1) {
            cout << sum[right - 1] - sum[left - 1] << endl;
        } else {
            cout << 0 << endl;  // No elements in range
        }
    }

    return 0;
}