#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
int sum[200005];
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i]; // Adjusted index to be 1-based for direct use with x array
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x, x + n, L) - x; // Start from the beginning of the array
        int r = upper_bound(x, x + n, R) - x; // Start from the beginning of the array
        cout << sum[r] - sum[l] << endl; // Corrected the summation range using 1-based index
    }
}