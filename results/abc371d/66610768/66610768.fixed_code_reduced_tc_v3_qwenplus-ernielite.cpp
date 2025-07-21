#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i]; // Assuming b is a copy of a for simplicity
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) c[i] = c[i - 1] + b[i]; // Accumulate sum of b up to current index
    }
    
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // Binary search in a to find the indices of l and r in a (assuming a is sorted)
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin() - 1; // Subtract 1 because of 0-based indexing of vector
        auto r_j = upper_bound(a.begin() + 1, a.end(), r) - a.begin() - 1; // Subtract 1 for 0-based indexing
        
        // Check if l or r are actually in the array (account for out-of-bounds case)
        if (l_i < 0 || r_j >= n || l > a[r_j] || l < a[l_i]) {
            // If out of bounds or not found, print -1 or handle accordingly (depends on problem requirements)
            cout << "-1" << endl; // Example output for an invalid query, adjust as needed
            continue; // Skip to next query if this one is invalid
        }
        // Calculate the range query based on the indices found in b (which is assumed to be sorted)
        if (r >= a[n]) { // If right bound is the maximum value, use prefix sum calculation for efficiency
            cout << c[r_j] << endl; // Output the sum from index 0 to r_j-1 in c (inclusive)
        } else { // Otherwise, calculate the difference between two prefix sums using c array
            cout << c[r_j] - c[l_i] << endl; // Output the difference between c at r_j and l_i indices
        }
    }
    return 0;
}