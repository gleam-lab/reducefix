#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
map<int, int> sum;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    // Initialize the prefix sum array
    sum[0] = 0;

    // Compute the prefix sums
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Since the array is 1-indexed, adjust L and R accordingly
        int c = lower_bound(x, x + n, L) - x;
        int d = upper_bound(x, x + n, R) - x;
        
        // Output the sum from index c to d-1
        cout << sum[d - 1] - sum[c - 1] << endl;
    }

    return 0;
}