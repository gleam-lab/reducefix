#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q, p_inv, q_inv;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        ld s = (ld)p_inv[i] * p[i];
        ld t = (ld)q_inv[i] * q[i];
        int x = mid / a[i];

        total_cost += (x * s) + (temp - (x * a[i])) * t;
    }

    return ceil(total_cost) <= x;
}

signed main() {
    cin >> n >> x;
    if (n == 0) return 0;
    
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    p_inv.resize(n); q_inv.resize(n);
    int div = std::gcd(n, __gcd(std::gcd(p[0], q[0]), std::gcd(p[1], q[1])));
    for (int i = 0; i < n; i++) {
        a[i] = __gcd(a[i], div);
        p[i] = p[i] / (p[i] / __gcd(p[i], q[i]));
        q[i] = q[i] / (p[i] / __gcd(p[i], q[i]));
        p_inv[i] = a[i] * p[i] / __gcd(a[i], div);
        q_inv[i] = b[i] * q[i] / __gcd(a[i], div);
    }

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) / 2;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}