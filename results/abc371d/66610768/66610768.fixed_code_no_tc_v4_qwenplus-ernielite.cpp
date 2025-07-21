#include <bits/stdc++.h>
using namespace std;
// Using int64_t instead of long long for clarity and consistency
typedef int64_t ll;
const int N = 1e6 + 7;

int main() {
    int n, m;
    cin >> n;
    // Initialize arrays a, b, and c with size n+1 (0-indexed)
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    // Read values into array a
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // Accumulate prefix sums of b into c (prefix sum of an array is an array where each element is the sum of elements up to that index)
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i] + c[i - 1]; // Here c[i - 1] should be added first to correctly compute prefix sum
    }

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r; // Read the query range [l, r]
        // Binary search for the index in array a where l is found or would be inserted
        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        // Binary search for the index in array a where r is found or would be inserted (exclusive)
        auto r_j = upper_bound(a.begin() + 1, a.end(), r); // Note: This should be exclusive for range queries, not inclusive
        // Adjust indices for 0-based indexing and handle the edge case where l is greater than the last element in a
        int i = l_i - a.begin() - 1; // Convert 0-based index for lower_bound (if we are at the end, use n)
        int j = r_j - a.begin() - 1; // Convert 0-based index for upper_bound (if it's out of bounds, use n)
        // If l is greater than the last element in a, we need to output the total sum from c
        if (l > a.back()) {
            cout << c[n] << endl; // No need to subtract anything, since there's no preceding value to subtract from in this case.
        } else { // If we are within bounds of the array or r is actually out of bounds as well.
            if (r >= a[0]) { // Check if r is not smaller than the first element in a, as in this case there's no preceding value to subtract from c[i-1].
                cout << c[j] - c[i] << endl; // Output the difference in prefix sums between r's position and l's position.
            } else { // If r is smaller than the first element in a, we need to output the sum before l's position.
                cout << c[i - 1] << endl; // Output the prefix sum before l's position in c.
            }
        }
    }
    return 0;
}