#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, x;
vector<ll> a, b, q, p;

// Cost function to calculate the total cost for a given production capacity 'mid'
ll cost(ll mid) {
    ll total_cost = 0;
    for (int i = 0; i < n; ++i) {
        ll s = p[i] * mid / a[i];
        ll t = q[i] * mid / b[i];
        total_cost += min(s, t);
    }
    return total_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n), b.resize(n), p.resize(n), q.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ll left = 0, right = 1e10;
    while (left < right) {
        ll mid = left + (right - left + 1) / 2;
        if (cost(mid) <= x) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;

    return 0;
}