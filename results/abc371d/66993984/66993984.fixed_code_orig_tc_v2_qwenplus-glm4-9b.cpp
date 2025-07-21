#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
map<int, int>sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int lb = upper_bound(x + 1, x + n + 1, L) - x;
        int ub = lower_bound(x + 1, x + n + 1, R + 1) - x; // Note the range [L, R]

        // Adjust the upper bound if R is not present in the array
        if (x[ub] != R) {
            ub--;
        }

        // Output the sum for the range [L, R]
        cout << sum[ub] - sum[lb - 1] << endl;
    }
}