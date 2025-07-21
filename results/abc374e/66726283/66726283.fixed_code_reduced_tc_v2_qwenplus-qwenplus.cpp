#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], p[N], b[N], q[N];

bool check(int mid) {
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        int min_cost = numeric_limits<int>::max();
        // Try all possible number of type A attacks
        for (int j = 0; j <= b[i]; ++j) {
            int damage_from_A = j * a[i];
            int remaining = max(0LL, mid - damage_from_A);
            int k = (remaining + b[i] - 1) / b[i]; // ceil division
            if (k > j) continue; // We can't use more B attacks than j
            int cost = j * p[i] + k * q[i];
            min_cost = min(min_cost, cost);
        }
        // Try all possible number of type B attacks
        for (int j = 0; j <= b[i]; ++j) {
            int damage_from_B = j * b[i];
            int remaining = max(0LL, mid - damage_from_B);
            int k = (remaining + a[i] - 1) / a[i]; // ceil division
            if (k > j) continue; // We can't use more A attacks than j
            int cost = j * q[i] + k * p[i];
            min_cost = min(min_cost, cost);
        }
        total += min_cost;
        if (total > x)
            return false;
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

    int l = 0, r = 1e18;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
    return 0;
}