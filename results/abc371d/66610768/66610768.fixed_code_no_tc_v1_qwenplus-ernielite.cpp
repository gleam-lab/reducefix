#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6; // Change the constant to a reasonable value based on the problem constraints

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1, 0); // Initialize c with zeros
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i]; // Assuming b is an array of values to be added to c (though this is not clear from the problem description)
        c[i] = c[i - 1] + b[i]; // Accumulate the sum of b into c
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r; // Read the range [l, r] for query
        // Find the indices of l and r in array a (taking into account 1-based indexing)
        auto l_i = lower_bound(a.begin(), a.end(), l) - a.begin();
        auto r_i = upper_bound(a.begin(), a.end(), r) - a.begin() - 1; // Decrement and subtract 1 to handle 1-based indexing properly
        if (l_i > r_i) { // Check if l is greater than r, which is an invalid query case
            continue; // Skip this query or handle it appropriately based on problem requirements
        }
        // The following if-else structure is not clear from the provided description and might need to be modified based on the problem requirements
        if (r >= n || r >= a[n]) { // Check if r is out of bounds or if it's a special case for 'r' being greater than or equal to the last element of a
            // Assuming we need to print the sum from index i-1 to the end of c (inclusive) for some reason
            cout << c[n] << endl; // Print the last element of c as it's the sum up to n
        } else {
            // Assuming we need to print the sum from index i-1 up to but not including j in c (exclusive) for some reason
            cout << c[r_i] - c[l_i - 1] << endl; // Print the difference between c[j-1] and c[i-1] as per the original code's logic (although there's no direct mapping between i, j, and l, r in this case)
        }
    }
    return 0;
}