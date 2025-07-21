#include <bits/stdc++.h>
using namespace std;

int n, q;
int x[200005], p[200005];
long long sum[200005]; // Use long long for larger sums

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    // Calculate prefix sums of p[] array (not shown in your code)
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Make sure you're using a data type that can hold larger values
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        // Find indices of L and R in the sorted array x[] (inclusive)
        auto l = lower_bound(x + 1, x + n + 1, L) - x;
        auto r = upper_bound(x + 1, x + n + 1, R) - x - 1; // Decrement by 1 since we're using half-open intervals [l, r)
        // Now l and r are indices into the prefix sum array sum[]
        // Calculate the sum from l to r (inclusive) using prefix sums
        long long result = sum[r] - sum[l - 1]; // Use long long to handle potential overflows
        cout << result << endl; // Output the result
    }
    return 0;
}