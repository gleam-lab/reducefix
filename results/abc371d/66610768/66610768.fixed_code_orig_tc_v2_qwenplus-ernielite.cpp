#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), c(n+1, 0); // Assuming b is not needed in this problem.
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // Calculate prefix sum of a[]
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + a[i]; // Sum of elements from 1 to i in a[]
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r; // l and r are 1-indexed positions in a[]
        auto l_it = lower_bound(a.begin(), a.end(), l); // Find position of l in a[] (inclusively)
        auto r_it = upper_bound(a.begin(), a.end(), r); // Find position of r in a[] (exclusively)
        int l_index = distance(a.begin(), l_it); // Get 0-indexed position of l in a[]
        int r_index = distance(a.begin(), r_it) - 1; // Get 0-indexed position of r in a[] (exclusive)
        // Calculate range sum (inclusive) from prefix sum array c[]
        if (r >= a[n]) { // Check if r is out of bounds of a[]
            cout << c[n] << endl; // If so, return c[n] as range sum is same as sum of all elements in a[]
        } else if (l > r) { // If l is greater than r, return 0 as no elements in range [l, r]
            cout << "0" << endl; // or throw an error if such case is not allowed in problem statement.
        } else { // Normal case: calculate range sum using prefix sums.
            cout << c[r_index] - c[l_index - 1] << endl; // Subtract previous element's sum from current element's sum to get range sum. Adjust index for 0-based indexing.
        }
    }
    return 0;
}