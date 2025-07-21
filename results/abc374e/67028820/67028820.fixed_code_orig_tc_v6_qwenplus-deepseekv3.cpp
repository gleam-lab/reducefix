#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        int cost_a = p[i];
        int cost_b = q[i];
        int batch_a = a[i];
        int batch_b = b[i];

        int full_a = remaining / batch_a;
        int full_b = remaining / batch_b;

        int cost_full_a = full_a * cost_a;
        int cost_full_b = full_b * cost_b;

        int rem_a = remaining % batch_a;
        int rem_b = remaining % batch_b;

        int cost_rem_a = (rem_a + batch_b - 1) / batch_b * cost_b;
        int cost_rem_b = (rem_b + batch_a - 1) / batch_a * cost_a;

        int option1 = cost_full_a + cost_rem_a;
        int option2 = cost_full_b + cost_rem_b;

        total_cost += min(option1, option2);

        if (total_cost > x) {
            return false;
        }
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;
    while (left < right) {
        int mid = left + (right - left + 1) / 2;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}