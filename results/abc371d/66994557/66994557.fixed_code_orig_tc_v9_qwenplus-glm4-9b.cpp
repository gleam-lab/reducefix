#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
int sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        sum[i] = sum[i - 1] + p[i]; // We should be accumulating p[i] in the first pass
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x + 1, x + n + 1, L) - x;
        int r = upper_bound(x + 1, x + n + 1, R) - x;
        cout << sum[r - 1] - sum[l - 1] << endl; // Adjusted for off-by-one
    }
}