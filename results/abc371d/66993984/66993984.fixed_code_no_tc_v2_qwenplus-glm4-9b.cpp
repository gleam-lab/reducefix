#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
long long sum[200005]; // Use long long to prevent overflow

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        p[i] = x[i]; // Store p as x for convenience
        sum[i + 1] = sum[i] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        if (L > R) {
            swap(L, R); // Ensure L is less than or equal to R
        }
        int c = lower_bound(x, x + n, L) - x;
        int d = upper_bound(x, x + n, R) - x;
        if (d <= c) {
            cout << 0 << endl; // If no elements are included, sum is 0
        } else {
            cout << sum[d - 1] - sum[c - 1] << endl; // Adjust index for sum array
        }
    }
    return 0;
}