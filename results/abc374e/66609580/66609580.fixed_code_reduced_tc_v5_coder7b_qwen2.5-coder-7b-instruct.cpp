#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool check(const vector<int>& a, const vector<int>& p, const vector<int>& b, const vector<int>& q, int n, long long x, long long target) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && b[i] == 0) continue;
        long long lcm_ab = lcm(a[i], b[i]);
        long long units_s = min(target / a[i], x / p[i]);
        long long units_t = min(target / b[i], x / q[i]);
        long long cost_s = units_s * p[i];
        long long cost_t = units_t * q[i];
        long long units_used = min(units_s, units_t);
        x -= cost_s + cost_t;
        target -= units_used * lcm_ab;
    }
    return target >= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;
    vector<int> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long left = 0, right = 1e18;
    while (left < right) {
        long long mid = (left + right + 1) / 2;
        if (check(a, p, b, q, n, x, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;
    return 0;
}