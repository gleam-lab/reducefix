#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

using ll = long long;

int gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

ll min(ll a, ll b) {
    return a < b ? a : b;
}

struct SegmentTree {
    vector<ll> tree;
    int n;

    SegmentTree(int _n) : n(_n), tree(_n * 2) {}

    void update(int i, ll val) {
        i += n;
        tree[i] = val;
        while (i > 1) {
            i >>= 1;
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    ll query(int l, int r) {
        ll ans = LLONG_MAX;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = min(ans, tree[l++]);
            if (r & 1) ans = min(ans, tree[r--]);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    vector<pair<ll, ll>> a_pairs(n);
    for (int i = 0; i < n; ++i) {
        ll a, b, p, q;
        cin >> a >> p >> b >> q;
        a_pairs[i] = {gcd(a, b), lcm(a, b)};
    }

    sort(a_pairs.begin(), a_pairs.end());

    SegmentTree seg(100000);

    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        ll g = a_pairs[i].first;
        ll lcm_ab = a_pairs[i].second;
        ll lcm_1 = lcm_ab / a_pairs[i].first;
        seg.update(1, max(0LL, (x / lcm_ab - 1) * lcm_1));
        cnt += seg.query(1, seg.n);

        if (cnt > x) break;
    }

    cout << cnt << '\n';
    return 0;
}