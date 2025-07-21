#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
long long n, x, a[MAXN], p[MAXN], b[MAXN], q[MAXN];

// Function to check if we can achieve at least 'target' production capacity with the given budget
bool check(long long target) {
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        // Calculate the cost to achieve 'target' production capacity for process i
        long long cost = min(
            (target + b[i] - 1) / b[i] * q[i], // Cost using machine T_i
            (target + a[i] - 1) / a[i] * p[i]  // Cost using machine S_i
        );
        sum += cost;
    }
    return sum <= x;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 1e7, mid, ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}