#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

const int MAXN = 110;
typedef long long ll;

ll a[MAXN], b[MAXN], p[MAXN], q[MAXN];
ll n, x;

bool check(ll v) {
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        ll _lcm = a[i] / gcd(a[i], b[i]) * b[i];
        ll vm = max(0LL, (v / _lcm - 1) * min(p[i] * (_lcm / a[i]), q[i] * (_lcm / b[i])));
        cnt += vm;
        ll val = max(0LL, v / _lcm - 1) * _lcm, ms = LLONG_MAX >> 1;
        for (ll j = 0; (j - 1) * a[i] <= v - val; ++j) {
            ms = min(ms, j * p[i] + max(0LL, ((v - val - j * a[i]) / b[i] +
                !!((v - val - j * a[i]) % b[i])) * q[i]));
        }
        cnt += ms;
        if (cnt > x) return false;
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

    ll l = 0, r = ULLONG_MAX;
    while (l + 1 < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l << endl;

    return 0;
}