#include<bits/stdc++.h>
using namespace std;

int n, q;
int x[200005]; // Assuming x is a sorted list of distinct elements
int p[200005]; // p array as given in the problem
int sum[200005]; // Corrected size to account for prefix sums

// Function to calculate the prefix sum (to be used later)
void calculatePrefixSums(int n, int p[]) {
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + p[i]; // Corrected prefix sum calculation
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i]; // Assuming x is a sorted list of distinct elements
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; // Read p values as given in the problem
    }
    calculatePrefixSums(n, p); // Calculate prefix sums for p array
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r; // Read l and r for each query
        // Use binary search to find the index of l and r in x array (assuming x is sorted)
        l = lower_bound(x + 1, x + n + 1, l) - x; // Find index of l (corrected)
        r = upper_bound(x + 1, x + n + 1, r) - x - 1; // Find index of r - 1 (corrected for upper bound)
        // Check if l and r are valid indices within the x array (accounting for edge cases)
        if (l > n || r < 0 || l > r) {
            // If invalid indices, output some appropriate message or handle the error case
            continue; // Skip this query or output an error message as per problem requirements
        }
        // Output the sum from l-1 to r-1 in the prefix sum array (corrected)
        cout << sum[r] - sum[l - 1] << endl; // Corrected output statement for query result
    }
    return 0;
}