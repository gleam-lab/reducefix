#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp_cost = 0;
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];

        if (s < t) {
            int x = min(mid / a[i], (int)(t * a[i]));
            temp_cost += x * p[i];
            mid -= x * a[i];
            temp_cost += mid * t;
        } else {
            int x = min(mid / b[i], (int)(s * b[i]));
            temp_cost += x * q[i];
            mid -= x * b[i];
            temp_cost += mid * s;
        }

        total_cost += temp_cost;
    }

    return (int)total_cost <= x;
}

int main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canMake(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left;
    return 0;
}