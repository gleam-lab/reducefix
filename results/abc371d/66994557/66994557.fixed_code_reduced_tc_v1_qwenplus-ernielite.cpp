#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> x(n), p(n);
    vector<long long> sum(n + 1); // Use long long for larger sums

    // Read the elements of x and p
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i]; // Calculate prefix sum
    }

    cin >> q;
    while (q--) {
        long long L, R; // Use long long to avoid overflow in sum calculations
        cin >> L >> R;
        // Find the indices of L and R in x using binary search (lower_bound and upper_bound)
        auto l = lower_bound(x.begin(), x.end(), L) - x.begin();
        auto r = upper_bound(x.begin(), x.end(), R) - x.begin() - 1; // Subtract 1 to get correct index for R
        // Calculate the sum between the two indices (inclusive of l and exclusive of r)
        long long result = sum[r] - sum[l]; // Use long long to avoid overflow when subtracting
        cout << result << endl; // Output the result of the query
    }
    return 0;
}