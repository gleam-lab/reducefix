#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

bool check(vector<ll>& a, vector<ll>& p, vector<ll>& b, vector<ll>& q, ll x, ll v) {
    ll cnt = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        ll lcm = a[i] / gcd(a[i], b[i]) * b[i];
        ll vm = max(0LL, (v / lcm - 1) * min(p[i] * (lcm / a[i]), q[i] * (lcm / b[i])));
        cnt += vm;
        ll val = max(0LL, v / lcm - 1) * lcm, ms = numeric_limits<ll>::max() >> 1;
        for (ll j = 0; (j - 1) * a[i] <= v - val; ++j) {
            ms = min(ms, j * p[i] + max(0LL, ((v - val - j * a[i]) / b[i] + !!((v - val - j * a[i]) % b[i])) * q[i]));
        }
        cnt += ms;
        if (cnt > x) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), p(n), b(n), q(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    ll l = 0, r = numeric_limits<ll>::max() >> 1;
    while (l + 1 < r) {
        ll mid = l + (r - l) / 2;
        if (check(a, p, b, q, x, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;
    return 0;
}