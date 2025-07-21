#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n;
int x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        c[i] = LLONG_MAX;
        // Try all possible combinations of type A and type B attacks
        // Since both are bounded by b[i], we loop j from 0 to b[i]
        for (int j = 0; j <= b[i]; j++) {
            int attackA = j;
            int remaining_monsters = mid - j * a[i];
            if (remaining_monsters <= 0) {
                c[i] = min(c[i], j * p[i]);
                continue;
            }
            int attackB_needed = (remaining_monsters + b[i] - 1) / b[i];
            c[i] = min(c[i], j * p[i] + attackB_needed * q[i]);
        }

        // Try all possible combinations of type B and type A attacks
        for (int j = 0; j <= b[i]; j++) {
            int attackB = j;
            int remaining_monsters = mid - j * b[i];
            if (remaining_monsters <= 0) {
                c[i] = min(c[i], j * q[i]);
                continue;
            }
            int attackA_needed = (remaining_monsters + a[i] - 1) / a[i];
            c[i] = min(c[i], j * q[i] + attackA_needed * p[i]);
        }
    }

    int total_cost = 0;
    for (int i = 1; i <= n; i++) {
        total_cost += c[i];
        if (total_cost > x) return false;
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 1, r = 1e18; // Use large upper bound as initial guess
    int answer = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            answer = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << answer;
    return 0;
}