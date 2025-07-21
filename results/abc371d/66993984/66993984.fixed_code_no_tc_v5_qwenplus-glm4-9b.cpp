#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
map<int, int, greater<int>> sum; // Use a map with greater to sort the indices in descending order

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = i; // Store the index
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x + 1, x + n + 1, L) - (x + 1); // Corrected to use array access
        int d = upper_bound(x + 1, x + n + 1, R) - (x + 1); // Corrected to use array access
        // Output the difference of cumulative sums
        cout << (sum[d] > sum[c] ? sum[d] - sum[c] : 0) << endl; // Ensure we don't subtract in reverse order
    }
    return 0;
}