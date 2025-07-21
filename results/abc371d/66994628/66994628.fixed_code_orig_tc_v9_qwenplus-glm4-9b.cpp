#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
long long x[MAX_N], p[MAX_N], sum[MAX_N];

int main() {
    int n, q;
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
        int l, r;
        cin >> l >> r;
        l = lower_bound(x + 1, x + n + 1, l) - x;
        r = upper_bound(x + 1, x + n + 1, r) - x;
        // Ensure we do not go out of bounds of the sum array
        if (l > 0 && r > n) {
            cout << sum[r - 1] - sum[l - 1] << endl;
        } else {
            cout << "Indices out of bounds" << endl;
        }
    }
    return 0;
}