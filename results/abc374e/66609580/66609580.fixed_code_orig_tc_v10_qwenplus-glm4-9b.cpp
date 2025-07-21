#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (b) swap(a, b), a %= b;
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    vector<pair<ll, pair<ll, ll>>> a, b;
    for (int i = 0; i < n; ++i) {
        ll ai, bi, pi, qi;
        cin >> ai >> pi >> bi >> qi;
        a.emplace_back(ai, {pi, bi});
        b.emplace_back(bi, {qi, ai});
    }

    auto check = [&](ll v) {
        ll cnt = 0;
        for (auto& [ai, p] : a) {
            ll lcm = ai / gcd(ai, p.first) * p.first;
            ll vm = max(0LL, (v / lcm - 1) * min(p.second * (lcm / ai), p.first * (lcm / p.first)));
            cnt += vm;
            if (cnt > x) return 0;
        }
        return 1;
    };

    ll l = 0, r = 1e18;
    while (l + 1 < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l + 1 << '\n';
    return 0;
}