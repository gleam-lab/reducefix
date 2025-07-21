#include <iostream>
#include <vector>
#include <algorithm> // For lower_bound and upper_bound
using namespace std;

int main() {
    int n, q;
    cin >> n; // Read the number of elements in x and p
    vector<int> x(n), p(n), sum(n); // Declare vectors with correct sizes

    // Read x and p arrays
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        p[i] = 0; // Assuming p is initially 0, you might need to adjust this based on your problem statement
    }
    // Calculate prefix sum of p (if needed)
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + p[i]; // Only calculate prefix sum if p is needed for sum calculation
    }

    cin >> q; // Read the number of queries
    while (q--) {
        int l, r;
        cin >> l >> r; // Read the query range [l, r] (inclusive)
        // Calculate the sum of p elements in the range [l, r] using prefix sum (if p is relevant)
        if (r > 0) { // Check for edge case where r is 0 or negative (out of bounds)
            cout << sum[r] - (sum[l - 1] ? sum[l - 1] : 0) << endl; // Use conditional operator to handle l == 1 case (l-1 might be out of bounds)
        } else {
            cout << "Invalid query range" << endl; // Output an error message if the range is invalid (e.g., l > r)
        }
    }
    return 0; // Don't forget to return 0 to indicate successful execution
}