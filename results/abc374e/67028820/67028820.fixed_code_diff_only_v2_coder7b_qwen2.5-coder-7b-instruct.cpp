#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

// Function to check if it's possible to make at least 'mid' units with given constraints
bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];

        // Calculate how many units we can get from product A and B
        int x_a = min(temp / a[i], mid / a[i]);
        int x_b = min(temp / b[i], mid / b[i]);

        // Update total cost based on which product is more efficient
        if (x_a * s >= x_b * t) {
            total_cost += x_a * p[i];
            temp -= x_a * a[i];
        } else {
            total_cost += x_b * q[i];
            temp -= x_b * b[i];
        }

        // Add remaining cost if any
        total_cost += temp * max(s, t);
    }

    return (int)(ceil(total_cost)) <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n), b.resize(n), p.resize(n), q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right) / 2;

        if (canMake(mid)) left = mid + 1;
        else right = mid;
    }

    cout << left - 1;

    return 0;
}