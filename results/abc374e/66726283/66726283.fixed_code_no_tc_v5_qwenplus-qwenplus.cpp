#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], b[N], p[N], q[N];

int c[N];

bool check(int mid) {
    for (int i = 1; i <= n; ++i) {
        c[i] = LLONG_MAX;
        // Try all possible numbers of type A potions bought
        for (int j = 0; j <= b[i]; ++j) {
            int damage_from_A = j * a[i];
            int remaining = max(0LL, mid - damage_from_A);
            int k = (remaining + b[i] - 1) / b[i]; // Number of B potions needed
            if (k > b[i]) continue; // Skip invalid combinations
            c[i] = min(c[i], j * p[i] + k * q[i]);
        }
        // Try all possible numbers of type B potions bought
        for (int j = 0; j <= b[i]; ++j) {
            int damage_from_B = j * b[i];
            int remaining = max(0LL, mid - damage_from_B);
            int k = (remaining + a[i] - 1) / a[i]; // Number of A potions needed
            if (k > b[i]) continue; // Skip invalid combinations
            c[i] = min(c[i], j * q[i] + k * p[i]);
        }
    }

    int total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        total_cost += c[i];
    }

    return total_cost <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search over the answer (damage)
    int l = 1, r = 1e6;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << r << "\n";
    return 0;
}