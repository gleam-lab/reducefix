#include <bits/stdc++.h>
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
        int L, R;
        cin >> L >> R;
        // Adjust indices to be zero-based for binary search
        auto it1 = lower_bound(x + 1, x + n + 1, L);
        auto it2 = upper_bound(x + 1, x + n + 1, R);
        int l = distance(x + 1, it1);
        int r = distance(x + 1, it2);
        if (l > r) {
            cout << 0 << endl;
        } else {
            cout << sum[r] - sum[l - 1] << endl;
        }
    }
    return 0;
}