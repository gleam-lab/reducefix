#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i]; // Read n elements into x
    // Assuming p is not needed, we can remove its declaration and related code.
    // vector<ll> p(n), s(n+1); // Remove this line and anything that uses p or s if not needed.
    vector<ll> s(n + 1); // If s is needed, ensure it has enough space for partial sums.
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + x[i]; // Calculate partial sums of x.
    }
    
    int q;
    cin >> q; // Read number of queries.
    for (int i = 0; i < q; i++) {
        int l, r; // Read l and r for each query.
        cin >> l >> r; // Read l and r from user input.
        // Check if l and r are within bounds before using them to calculate the sum.
        if (l <= 0) l = 1; // Handle l being less than 1 (or any other appropriate boundary condition).
        if (r > n) r = n; // Handle r going out of bounds (or any other appropriate boundary condition).
        // Use binary search to find indices for l and r in x. Adjust if necessary for edge cases.
        int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
        int rt = upper_bound(x.begin(), x.end(), r) - x.begin(); // Note: This will be one less than actual index if r is found.
        // Calculate the sum between indices lt (inclusive) and rt (exclusive).
        ll ans = s[rt] - s[lt]; // Correct calculation of sum using partial sums array s.
        cout << ans << endl; // Output the result for this query.
    }
    return 0; // End of main function.
}