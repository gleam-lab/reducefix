#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
long long sum[200005]; // Using long long for larger numbers

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i]; // Assuming x is a sorted array (by value) for binary search operations
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; // p represents some values associated with x elements (e.g., frequencies)
        sum[i] = sum[i - 1] + p[i]; // Correctly updating prefix sum array
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R; // Reading query range [L, R] from user input
        // Binary search for lower bound and upper bound indices in x array (assuming it's sorted)
        int c = lower_bound(x + 1, x + n + 1, L) - x; // Corrected usage of lower_bound for L index
        int d = upper_bound(x + 1, x + n + 1, R) - x - 1; // Corrected usage of upper_bound for R index and decrementing by 1 (since we want one less than upper bound)
        // Now we have indices c and d (inclusive) that represent our query range in p array/sum array (depending on context)
        // Calculate the difference in prefix sums (using long long for accurate results)
        long long result = (sum[d] - sum[c - 1]); // Corrected calculation of range sum query using prefix sums
        cout << result << endl; // Outputting result of query range sum calculation
    }
    return 0; // Returning from main function as per usual practice (even if it's not strictly necessary in this case)
}