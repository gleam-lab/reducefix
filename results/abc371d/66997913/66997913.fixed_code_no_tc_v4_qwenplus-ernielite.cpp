#include <iostream>
#include <vector>
#include <algorithm> // For upper_bound and lower_bound

using namespace std;
using ll = long long; // long long for efficient number handling

int main() {
    int n;
    cin >> n; // Read the number of elements in the array
    vector<int> x(n); // Declare the array to hold the elements
    for (int i = 0; i < n; i++) cin >> x[i]; // Read the elements into the array

    // We need to add a new vector to store the prefix sum, and an additional space for s[0] to hold a 0 (base case)
    vector<ll> s(n + 1, 0); // Initialize the prefix sum vector with 0s
    for (int i = 1; i <= n; i++) { // Start at 1 since we want s[i] to be a sum from index 0 to i-1
        s[i] = s[i - 1] + (ll)x[i - 1]; // Calculate the prefix sum
    }

    // Now we can read the number of queries and process them
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; // l and r are for left and right bounds of the query range
        cin >> l >> r; // Read the query range bounds
        // Since we are using 0-based indexing in our prefix sum array, we need to adjust the bounds accordingly.
        // We also want to avoid going out of bounds by checking that l is not greater than r.
        if (l > r) continue; // If l is greater than r, it's an invalid query, so skip it.
        int lt = lower_bound(x.begin(), x.end(), l) - x.begin(); // Find left boundary of the range in x[]
        int rt = upper_bound(x.begin(), x.end(), r) - x.begin() - 1; // Find right boundary of the range in x[] (subtract 1 for 0-based index)
        // Now we can calculate the sum of the range using prefix sums
        ll ans = s[rt + 1] - s[lt]; // Use s[rt+1] instead of s[rt] to avoid including the rightmost element in the sum.
        cout << ans << endl; // Output the result of the query sum
    }
    return 0; // Program finished successfully
}