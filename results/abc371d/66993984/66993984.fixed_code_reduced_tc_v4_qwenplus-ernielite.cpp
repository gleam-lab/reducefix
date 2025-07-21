#include <bits/stdc++.h>
using namespace std;

int n, q;
int x[200005];
long long p[200005]; // Assuming the sum of p[i] can be large, we use long long instead of int
map<int, long long> sum; // We also need to use long long for the sum of p[]

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        // Accumulate the prefix sum of p[]
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        // The query is to find the sum of p[] between L and R (inclusive) in the sorted array x[]
        // We need to find the indices of L and R in x[], and then calculate the difference in the sum.
        auto l_it = lower_bound(x, x + n + 1, L);
        auto r_it = upper_bound(x, x + n + 1, R); // Notice we're using the unordered map's iterator here.
        // Since we're using a map, we need to adjust the iterator to point to the correct index.
        // In a regular array, we would do: int c = c - 1; int d = d - 1; but since we're using a map, we don't need to adjust.
        // Now, we calculate the difference in the prefix sums and output it.
        cout << (r_it - l_it == 0 ? 0 : sum[r_it - 1] - sum[l_it - 1]) << endl; // Check for empty range.
    }
    return 0;
}