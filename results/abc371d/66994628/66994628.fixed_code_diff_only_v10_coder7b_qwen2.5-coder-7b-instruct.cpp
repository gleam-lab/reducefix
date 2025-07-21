#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Adjust indices to be zero-based for lower_bound and upper_bound
        l = lower_bound(x + 1, x + n + 1, l) - x;
        r = upper_bound(x + 1, x + n + 1, r) - x;
        if (l > r) {
            cout << "0" << endl; // Handle the case where no elements are within the range [l, r]
        } else {
            cout << sum[r] - sum[l - 1] << endl;
        }
    }
    return 0;
}