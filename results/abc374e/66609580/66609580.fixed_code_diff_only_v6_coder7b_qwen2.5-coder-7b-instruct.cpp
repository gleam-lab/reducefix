#include <bits/stdc++.h>
using namespace std;

#define dout(x) cerr << #x << " = " << x << endl;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define sz(v) ((ll)(v).size())

const int N = 110;

int n;
ll a[N], b[N], p[N], q[N], x;

bool check(ll v) {
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        ll _lcm = (a[i] / __gcd(a[i], b[i])) * b[i];
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
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll l = 0, r = UINT_MAX >> 1;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1;
    return 0;
}