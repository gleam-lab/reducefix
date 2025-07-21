#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
long long x;
long long a[N], b[N], p[N], q[N];

bool check(long long mid) {
    for (int i = 1; i <= n; ++i) {
        long long min_cost = INT_MAX;
        for (int j = 0; j <= b[i]; ++j) {
            min_cost = min(min_cost, j * p[i] + q[i] * ((mid - j * a[i] + b[i] - 1) / b[i]));
        }
        if (min_cost > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 1e18; // Adjust upper bound based on problem constraints
    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
    return 0;
}