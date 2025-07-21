#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> x(n), p(n); // Use vector instead of array for better performance and clarity
    map<int, int> sum; // Use a map to store the cumulative sum of p[] efficiently
    
    // Read x[] and p[] values
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i > 0) {
            sum[i] = sum[i - 1] + p[i]; // Calculate cumulative sum of p[]
        } else {
            sum[i] = p[i]; // For the first element, it's just the value of p[]
        }
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        // Find the indices of L and R in x[] using binary search (lower_bound and upper_bound)
        auto c_it = lower_bound(x.begin(), x.end(), L); // c_it is an iterator pointing to first occurrence of L in x[] (or end() if not found)
        auto d_it = upper_bound(x.begin(), x.end(), R); // d_it is an iterator pointing to first element greater than R in x[] (or end() if not found)
        // Calculate the range indices by subtracting begin() from the iterators and subtracting 1 to exclude the range's end index from sum[] query
        int c = distance(x.begin(), c_it) - 1; // c is the index of L in x[] (or n if L is greater than any value in x[])
        int d = distance(x.begin(), d_it) - 1; // d is the index of R in x[] (or n if R is greater than any value in x[])
        // If L is greater than any value in x[], or R is less than or equal to the first value in x[], we cannot find a valid range, so output 0. Otherwise, calculate the sum of p[] for the range.
        if (c >= 0 && d >= 0) { // Check if both c and d are valid indices (non-negative)
            cout << sum[d] - sum[c] << endl; // Output the sum of p[] for the range [c+1, d-1] (inclusive)
        } else {
            cout << "0" << endl; // Output 0 if no valid range is found (e.g., L > max(x) or R <= min(x))
        }
    }
    return 0;
}