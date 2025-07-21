#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];

        // Try both orderings: s first then t, and t first then s
        // Choose the one with minimum cost

        // Option 1: Use as much from a as possible
        ld cost1;
        {
            int countA = mid / a[i];
            int remaining = mid - countA * a[i];
            cost1 = (ld)countA * p[i] + (ld)remaining * t;
        }

        // Option 2: Use as much from b as possible
        ld cost2;
        {
            int countB = mid / b[i];
            int remaining = mid - countB * b[i];
            cost2 = (ld)countB * q[i] + (ld)remaining * s;
        }

        total_cost += min(cost1, cost2);
    }

    return (total_cost <= x + 1e-8); // Adding small epsilon to handle floating point precision
}

signed main() {
    cin >> n >> x;
    a.resize(n); p.resize(n); b.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) >> 1;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}