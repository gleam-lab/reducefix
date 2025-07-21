#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1), prefixSum(n+1, 0); // Added prefixSum for prefix sum array
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefixSum[i] = prefixSum[i - 1] + a[i]; // Calculate prefix sum
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // Use lower_bound to find index of first element >= l in a
        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        // Use upper_bound to find index immediately after first element > r in a
        auto r_i = upper_bound(a.begin() + 1, a.end(), r) - 1; // Subtract 1 as upper_bound returns one past the last element
        
        // Check if the query range is valid (i.e., l_i and r_i are within bounds)
        if (l_i == r_i + 1 && *l_i == l) { // Case when there is exactly one element between l and r (inclusive)
            cout << prefixSum[r_i] - prefixSum[l_i - 1] << endl; // Output prefix sum difference
        } else if (l_i == a.begin() && r_i == a.end()) { // Case when l is before all elements and r is after all elements (shouldn't happen)
            cout << "Invalid query" << endl; // Or any other appropriate response for an invalid query range
        } else { // Other cases where we have a valid query range within the array a
            cout << prefixSum[r_i] - prefixSum[l_i - 1] << endl; // Output prefix sum difference for the query range
        }
    }
    return 0;
}