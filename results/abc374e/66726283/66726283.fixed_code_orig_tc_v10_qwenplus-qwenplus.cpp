#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;

int a[N], p[N], b[N], q[N];

bool valid(int days) {
    int total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        int min_cost = LLONG_MAX;
        // Try all possible number of type A attacks (from 0 to how many can be used within days)
        for (int j = 0; j <= days / a[i] && j <= b[i]; ++j) {
            int remaining_days = days - j * a[i];
            int needed_q = max(0LL, (remaining_days + b[i] - 1) / b[i]);
            int cost = j * p[i] + needed_q * q[i];
            min_cost = min(min_cost, cost);
        }
        // Try all possible number of type B attacks
        for (int j = 0; j <= days / b[i] && j <= a[i]; ++j) {
            int remaining_days = days - j * b[i];
            int needed_p = max(0LL, (remaining_days + a[i] - 1) / a[i]);
            int cost = j * q[i] + needed_p * p[i];
            min_cost = min(min_cost, cost);
        }
        total_cost += min_cost;
        if (total_cost > x)
            return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int low = 1;
    int high = 1e18;
    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (valid(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}