#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    __int128 total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        __int128 s = p[i];
        s *= b[i];
        __int128 t = q[i];
        t *= a[i];

        if (s < t) {
            int x = mid / a[i];
            total_cost += x * p[i];
            temp -= x * a[i];
            total_cost += (temp * q[i] + b[i] - 1) / b[i];
        }
        else {
            int x = mid / b[i];
            total_cost += x * q[i];
            temp -= x * b[i];
            total_cost += (temp * p[i] + a[i] - 1) / a[i];
        }

        if (total_cost > x) return false;
    }

    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;
    while (left < right) {
        int mid = (left + right + 1) >> 1;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}