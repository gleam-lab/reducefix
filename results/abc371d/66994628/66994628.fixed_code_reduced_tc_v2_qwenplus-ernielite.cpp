#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
long long sum[200005]; // Use long long for larger numbers

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Calculate prefix sum of p
    }
    sort(x + 1, x + n + 1); // Sort the array x for binary search to work correctly

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Find indices for l and r using binary search
        l = lower_bound(x + 1, x + n + 1, l) - x;
        if (l > n) l = n; // If l is greater than n (out of range), set it to n
        r = upper_bound(x + 1, x + n, r) - x - 1; // Subtract 1 because upper_bound returns the index after the last element less than r
        if (r < 0) r = 0; // If r is out of range (before x[1]), set it to 0 for correct indexing of sum array
        // Output the sum of p values from l-1 to r-1 (inclusive) using the prefix sum array
        cout << sum[r] - sum[l - 1] << endl; // Subtracting 1 from l because sum is from index 1 to n
    }
    return 0;
}