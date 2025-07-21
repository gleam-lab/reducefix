#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1); // Initialize arrays with zeroes
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; // Assuming a[i] is a unique identifier for b[i] and c[i]
        b[i] = 0; // Initialize b[i] to zero for now, assuming it's a value that will be updated later
        c[i] = b[i]; // Initialize c[i] as prefix sum of b[i] (only needed if b is actually used)
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[a[i]]; // Populate b[] with values related to a[] (based on input)
        if (i > 1) c[i] = c[i - 1] + b[i]; // Calculate prefix sum of b[]
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r; // Read query range [l, r]
        // Binary search in a[] to find the indices corresponding to l and r
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin() - 1; // l_i is index of lower_bound(a, l) - 1 since we're looking for >= l
        auto r_i = upper_bound(a.begin() + 1, a.end(), r) - a.begin() - 1; // r_i is index of upper_bound(a, r) - 1 since we're looking for < r
        // Handle edge cases where the query range is not in the array bounds or if one endpoint is at the beginning/end
        if (r_i == 0 && l_i == n) { // If both l and r are out of bounds (which shouldn't happen with our lower/upper bounds)
            cout << "Invalid query" << endl; // Output an appropriate message or handle this case as needed
            continue; // Skip this query or handle it appropriately
        } else if (r_i == 0) { // If only l is out of bounds (shouldn't happen with our lower bound)
            cout << "Left out of bounds" << endl; // Handle this case appropriately (e.g., output zero or an error message)
            continue; // Skip this query or handle it appropriately
        } else if (l_i == n) { // If only r is out of bounds (shouldn't happen with our upper bound)
            cout << "Right out of bounds" << endl; // Handle this case appropriately (e.g., output zero or an error message)
            continue; // Skip this query or handle it appropriately
        } else { // Normal case where both l and r are within bounds of a[] and c[]
            // Calculate the range sum using prefix sum array c[] and indices l_i and r_i-1 (since we want inclusive range [l_i, r_i))
            cout << c[r_i] - c[l_i] << endl; // Output the difference in prefix sums to get the range sum query result
        }
    }
    return 0;
}