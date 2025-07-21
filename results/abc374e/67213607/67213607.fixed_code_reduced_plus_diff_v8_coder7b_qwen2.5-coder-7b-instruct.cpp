#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const long long INF = 2e18;

int n, x;
long long a[MAXN], p[MAXN], b[MAXN], q[MAXN];
long long l, r, mid, ans, minn, sum;

bool check(long long target) {
    long long total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        long long cost_a = INF, cost_b = INF;
        // Calculate minimum cost using item a
        for (int j = 0; j <= b[i]; ++j) {
            if ((target - j * a[i]) >= 0) {
                cost_a = min(cost_a, j * p[i] + (target - j * a[i]) / b[i] * q[i]);
            }
        }
        // Calculate minimum cost using item b
        for (int j = 0; j <= a[i]; ++j) {
            if ((target - j * b[i]) >= 0) {
                cost_b = min(cost_b, j * q[i] + (target - j * b[i]) / a[i] * p[i]);
            }
        }
        // Take the minimum of both costs
        total_cost += min(cost_a, cost_b);
    }
    return total_cost <= x;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0, r = 1000000005;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}