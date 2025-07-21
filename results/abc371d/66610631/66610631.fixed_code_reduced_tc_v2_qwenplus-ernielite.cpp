#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1), c(n+1); // We don't need b here, so we can remove it.
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = c[i - 1] + a[i]; // Precompute prefix sum of a[] for efficient range queries
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r; // Read the range [l, r] for query
        auto l_i = lower_bound(a.begin() + 1, a.end(), l); // Find index of first element >= l
        auto r_i = upper_bound(a.begin() + 1, a.end(), r) - 1; // Find index of last element < r (subtract 1 as upper_bound includes r)
        // Check if the range is empty or falls outside the array bounds
        if (l_i == a.begin() && r_i == a.end()) {
            cout << c[n] << endl; // If the range is empty, return the total sum from prefix sum array
        } else if (r_i == a.begin() || l_i == a.end()) {
            // If one of the endpoints is outside the array or at the wrong end, adjust the result accordingly
            cout << c[n] - c[r_i] << endl; // or cout << c[n] - c[l_i - 1]; depending on which end is outside
        } else {
            // If both endpoints are within the array, calculate the range sum using prefix sum array
            cout << c[r_i] - c[l_i - 1] << endl; // Subtract prefix sum at l_i-1 from prefix sum at r_i to get the range sum
        }
    }
    return 0;
}