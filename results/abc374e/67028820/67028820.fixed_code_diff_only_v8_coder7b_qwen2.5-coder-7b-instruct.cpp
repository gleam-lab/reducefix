#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

// Function to check if it's possible to make at least 'mid' units with given resources
bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];

        // Determine how much of resource i we can use from p or q based on their unit cost
        if (s < t) {
            int x = min(mid / a[i], (int)p[i] / a[i]);
            total_cost += x * p[i];
            temp -= x * a[i];
            total_cost += temp * t;
        } else {
            int x = min(mid / b[i], (int)q[i] / b[i]);
            total_cost += x * q[i];
            temp -= x * b[i];
            total_cost += temp * s;
        }
    }
    return ceil(total_cost) <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n), b.resize(n), p.resize(n), q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}