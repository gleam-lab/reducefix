#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], p[N], b[N], q[N];

int c[N];
bool check(int mid) {
    for (int i = 1; i <= n; ++i) {
        c[i] = LLONG_MAX;
        // Try all possible number of type A attacks (j)
        for (int j = 0; j <= b[i]; ++j) {
            int damageFromA = j * a[i];
            int remainingHP = max(0LL, mid - damageFromA);
            int neededB = (remainingHP + b[i] - 1) / b[i]; // ceil division
            if (neededB <= b[i]) { // Ensure we don't exceed the limit on B attacks
                c[i] = min(c[i], j * p[i] + neededB * q[i]);
            }
        }

        // Try all possible number of type B attacks (j)
        for (int j = 0; j <= b[i]; ++j) {
            int damageFromB = j * b[i];
            int remainingHP = max(0LL, mid - damageFromB);
            int neededA = (remainingHP + a[i] - 1) / a[i]; // ceil division
            if (neededA <= b[i]) { // Ensure we don't exceed the limit on A attacks
                c[i] = min(c[i], j * q[i] + neededA * p[i]);
            }
        }
    }

    int totalCost = 0;
    for (int i = 1; i <= n; ++i) {
        totalCost += c[i];
        if (totalCost > x) return false; // Early exit to avoid overflow
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

    int l = 1, r = 1e14; // Safe upper bound based on max possible HP per monster
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

    cout << answer << '\n';
    return 0;
}