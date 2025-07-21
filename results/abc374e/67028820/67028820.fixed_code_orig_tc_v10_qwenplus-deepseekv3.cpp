#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        int s_num = p[i];
        int s_den = a[i];
        int t_num = q[i];
        int t_den = b[i];

        int cost1 = (temp / a[i]) * p[i];
        int remaining1 = temp % a[i];
        int cost_part1 = cost1 + remaining1 * t_num / t_den;
        if (remaining1 * t_num % t_den != 0) {
            cost_part1 += 1;
        }

        int cost2 = (temp / b[i]) * q[i];
        int remaining2 = temp % b[i];
        int cost_part2 = cost2 + remaining2 * s_num / s_den;
        if (remaining2 * s_num % s_den != 0) {
            cost_part2 += 1;
        }

        total_cost += min(cost_part1, cost_part2);
        if (total_cost > x) {
            return false;
        }
    }
    return total_cost <= x;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

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