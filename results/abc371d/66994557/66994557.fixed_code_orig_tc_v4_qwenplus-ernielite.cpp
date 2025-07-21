#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005], sum[200005]; // We don't need more than 200005 elements for this problem.

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i]; // Read x values (they can be treated as unique identifiers or indices)
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; // Read p values (the actual query values)
        sum[i] = sum[i - 1] + p[i]; // Update the cumulative sum of p values
    }
    sort(x + 1, x + n + 1); // Sort the x array to enable binary search operations correctly.
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R; // Read the range query (L and R are the query values)
        int l = lower_bound(x + 1, x + n + 1, L) - x; // Find the index of the first element >= L in x. Adjust as needed if x values are not unique.
        int r = lower_bound(x + 1, x + n + 1, R + 1) - x - 1; // Find the index of the first element > R in x. Adjust for inclusive/exclusive range as needed.
        // Now, sum[r-1] - sum[l-1] represents the sum of p values in the range [L, R]. Output this value.
        cout << sum[r] - sum[l - 1] << endl; // Output the result of the range query. Adjust indexing as needed if l-1 goes out of bounds.
    }
    return 0; // Don't forget to return 0 to indicate successful execution.
}