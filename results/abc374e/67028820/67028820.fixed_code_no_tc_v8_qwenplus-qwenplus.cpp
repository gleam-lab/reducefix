#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, q, p;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Calculate the minimum number of full A and B packages needed
        int count_a = mid / a[i];
        int rem_a = mid % a[i];
        ld cost_a = count_a * p[i] + (ld)rem_a * ((ld)p[i] / a[i]);

        int count_b = mid / b[i];
        int rem_b = mid % b[i];
        ld cost_b = count_b * q[i] + (ld)rem_b * ((ld)q[i] / b[i]);

        total_cost += min(cost_a, cost_b);
    }

    return ceil(total_cost) <= x;
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
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}