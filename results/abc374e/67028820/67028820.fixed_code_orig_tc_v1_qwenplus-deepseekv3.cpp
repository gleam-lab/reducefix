#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; ++i) {
        int temp = mid;
        int cost1 = (temp / a[i]) * p[i];
        int remaining1 = temp % a[i];
        cost1 += remaining1 * ((q[i] + b[i] - 1) / b[i]); // Ceiling division: q[i]/b[i]

        int cost2 = (temp / b[i]) * q[i];
        int remaining2 = temp % b[i];
        cost2 += remaining2 * ((p[i] + a[i] - 1) / a[i]); // Ceiling division: p[i]/a[i]

        total_cost += min(cost1, cost2);
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;
    int answer = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canMake(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}