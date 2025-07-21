#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

int n, x;
int a[110], p[110], b[110], q[110];

inline int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

bool check(int v) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int g = __gcd(a[i], b[i]);
        int L = lcm(a[i], b[i]);

        // Full complete blocks of LCM
        int full_cycles = v / L;
        int block_cost = min(p[i] * (L / a[i]), q[i] * (L / b[i]));
        cnt += full_cycles * block_cost;

        if (cnt > x) return false;

        // Remaining part: [full_cycles * L + 1 ... v]
        int rem = v - full_cycles * L;

        int min_cost = INF;
        for (int j = 0; j * a[i] <= rem; ++j) {
            int rem_b = rem - j * a[i];
            int k = max(0LL, rem_b / b[i] + (rem_b % b[i] != 0));
            min_cost = min(min_cost, j * p[i] + k * q[i]);
        }

        cnt += min_cost;
        if (cnt > x) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> p[i] >> b[i] >> q[i];

    int l = 0, r = INF;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l << '\n';
}