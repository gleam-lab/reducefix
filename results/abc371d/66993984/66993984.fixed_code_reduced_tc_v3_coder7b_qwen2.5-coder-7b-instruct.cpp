#include <bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
long long sum[200005];

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
        auto it1 = lower_bound(x, x + n + 1, L);
        auto it2 = upper_bound(x, x + n + 1, R);
        int c = distance(x, it1);
        int d = distance(x, it2);
        if (c == n || x[c] > R) d--;
        cout << sum[d] - sum[c] << endl;
    }
    return 0;
}