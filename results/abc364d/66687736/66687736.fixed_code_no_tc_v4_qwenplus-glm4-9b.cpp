#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define vi vector<int>

int main() {
    ll n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    multiset<pair<int, int>> sorted_points;
    rep(i, n) {
        sorted_points.insert({a[i], i});
    }

    rep(i, q) {
        ll b, k;
        cin >> b >> k;
        auto it = sorted_points.lower_bound({b - k, numeric_limits<int>::min()});
        if (it == sorted_points.begin()) {
            cout << 2 * k << endl;
        } else {
            auto prev_it = prev(it);
            cout << abs(a[prev_it->second] - b) << endl;
        }
    }

    return 0;
}