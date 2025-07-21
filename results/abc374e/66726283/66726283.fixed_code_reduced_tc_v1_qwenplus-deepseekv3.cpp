#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], b[N], p[N], q[N];

bool check(int mid) {
    int total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        int min_cost = LLONG_MAX;
        // Try all possible j where j is the number of times we buy type a[i]
        for (int j = 0; j <= mid / a[i] + 2; ++j) {
            if (j * a[i] > mid) continue;
            int remaining = mid - j * a[i];
            int k = (remaining + b[i] - 1) / b[i]; // ceil(remaining / b[i])
            if (k < 0) k = 0;
            int cost = j * p[i] + k * q[i];
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
        // Try all possible j where j is the number of times we buy type b[i]
        for (int j = 0; j <= mid / b[i] + 2; ++j) {
            if (j * b[i] > mid) continue;
            int remaining = mid - j * b[i];
            int k = (remaining + a[i] - 1) / a[i]; // ceil(remaining / a[i])
            if (k < 0) k = 0;
            int cost = j * q[i] + k * p[i];
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
        total_cost += min_cost;
        if (total_cost > x) {
            return false;
        }
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

    int left = 0;
    int right = 1e18; // Sufficiently large upper bound
    int answer = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}