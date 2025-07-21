#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, q;
    cin >> n >> q; // First read the number of elements in x and the number of queries

    // Initialize and read the array x
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Initialize and calculate the prefix sum array s
    vector<ll> s(n + 1); // The prefix sum array should have one extra element at the end to handle the case where r is the last index.
    for (int i = 1; i <= n; i++) { // Start at index 1 to avoid accessing uninitialized memory at index 0.
        s[i] = s[i - 1] + (ll)x[i - 1]; // Calculate prefix sum, converting x[i-1] to long long if needed.
    }

    // Process queries
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r; // Read the left and right indices for each query
        // The range-based query is from index l (inclusive) to index r (inclusive) in x.
        // We need to adjust the indices for the prefix sum array s.
        int lt = l - 1; // Subtract 1 because we start reading at index 0 in x but at index 1 in s.
        int rt = r; // No adjustment needed for r as it's already an index in x.
        // Check for out-of-bounds conditions for lt and rt.
        if (lt < 0 || lt > n) { // Invalid left index
            cout << "Invalid query" << endl; // Handle the error appropriately.
            continue; // Skip this query and move on to the next one.
        }
        if (rt > n) { // Invalid right index (r is out of bounds)
            rt = n; // Adjust to the last valid index in s.
        }
        // Calculate and print the answer using the prefix sum array s.
        ll ans = s[rt + 1] - s[lt]; // Use correct data types for prefix sum array access and result.
        cout << ans << endl; // Print the result.
    }
    return 0;
}