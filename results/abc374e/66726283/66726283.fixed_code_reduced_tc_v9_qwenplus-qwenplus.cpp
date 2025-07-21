#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], p[N], b[N], q[N];

int compute_min_cost(int item, int mid) {
    int min_cost = LLONG_MAX;
    int max_j1 = b[item];
    for (int j = 0; j <= max_j1; j++) {
        int required_a = mid - j * a[item];
        if (required_a <= 0) {
            min_cost = min(min_cost, j * p[item]);
        } else {
            int full_bundles = (required_a + b[item] - 1) / b[item];
            min_cost = min(min_cost, j * p[item] + full_bundles * q[item]);
        }
    }

    int max_j2 = (mid + a[item] - 1) / a[item];
    for (int j = 0; j <= max_j2; j++) {
        int required_b = mid - j * b[item];
        if (required_b <= 0) {
            min_cost = min(min_cost, j * q[item]);
        } else {
            int full_bundles = (required_b + a[item] - 1) / a[item];
            min_cost = min(min_cost, j * q[item] + full_bundles * p[item]);
        }
    }

    return min_cost;
}

bool check(int mid) {
    int total_cost = 0;
    for (int i = 1; i <= n; i++) {
        int item_cost = compute_min_cost(i, mid);
        total_cost += item_cost;
        if (total_cost > x || total_cost < 0) { // handle overflow
            return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 0, r = 1e6;
    int answer = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            answer = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << answer;
    return 0;
}