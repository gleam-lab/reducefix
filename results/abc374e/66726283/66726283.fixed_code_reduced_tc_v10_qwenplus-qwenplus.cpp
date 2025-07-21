#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], p[N], b[N], q[N];

bool valid(int mid) {
    int total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        int min_cost = LLONG_MAX;
        // Try all possible number of type A attacks, and compute required type B attacks
        for (int j = 0; j <= b[i]; ++j) {
            int damage_from_A = j * a[i];
            int remaining_damage = max(0LL, mid - damage_from_A);
            int needed_B = (remaining_damage + b[i] - 1) / b[i]; // ceil division
            int cost = j * p[i] + needed_B * q[i];
            min_cost = min(min_cost, cost);
        }
        // Also try swapping roles: fix number of B attacks and calculate needed A
        for (int j = 0; j <= a[i]; ++j) {
            int damage_from_B = j * b[i];
            int remaining_damage = max(0LL, mid - damage_from_B);
            int needed_A = (remaining_damage + a[i] - 1) / a[i]; // ceil division
            int cost = j * q[i] + needed_A * p[i];
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

    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int low = 1, high = 1e18;
    int answer = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (valid(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}