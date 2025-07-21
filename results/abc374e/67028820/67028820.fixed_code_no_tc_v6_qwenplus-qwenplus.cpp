#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Calculate how much we can get from each machine with "mid" units of time
        ld rate_a = p[i] / (ld)a[i];  // profit per unit time for machine A
        ld rate_b = q[i] / (ld)b[i];  // profit per unit time for machine B

        if (rate_a > rate_b) {
            // Prefer machine A
            int count_a = mid / a[i];
            int remaining = mid % a[i];
            total_cost += count_a * p[i] + remaining * rate_b;
        } else {
            // Prefer machine B
            int count_b = mid / b[i];
            int remaining = mid % b[i];
            total_cost += count_b * q[i] + remaining * rate_a;
        }
    }

    return (int)(ceil(total_cost)) <= x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n); p.resize(n); b.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canMake(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left;

    return 0;
}