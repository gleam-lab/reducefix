#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        ld s = (ld)p[i] / a[i];
        ld t = (ld)q[i] / b[i];

        if (s < t) {
            int x = temp / a[i];
            total_cost += x * p[i];
            temp -= x * a[i];
            total_cost += ceil(temp * t);
        }
        else {
            int x = temp / b[i];
            total_cost += x * q[i];
            temp -= x * b[i];
            total_cost += ceil(temp * s);
        }
        
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}