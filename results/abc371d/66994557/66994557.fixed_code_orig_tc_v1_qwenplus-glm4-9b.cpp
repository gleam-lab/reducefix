#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
int sum[2000005]; // Adjusted size for the sum array

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    // Initialize sum[0] to 0
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i]; // Corrected sum array indexing
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x, x + n + 1, L) - x; // Adjust lower_bound to start from x
        int r = upper_bound(x, x + n + 1, R) - x; // Adjust upper_bound to start from x
        cout << sum[r] - sum[l - 1] << endl; // Correct index for range sum
    }
}