#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAX_N = 1e9;

bool inBounds(const pll &a, const ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<pll> q(m); for(ll i = 0; i < m; ++i) cin >> q[i].first >> q[i].second;
    
    set<ll> row, col, d1, d2;
    for(const auto &[i, j] : q) {
        row.insert(i); col.insert(j); d1.insert(i - j); d2.insert(i + j);
    }
    
    ll ans = n * n;
    ans -= (ll)row.size() * n;
    ans -= (ll)col.size() * n;
    ans += (ll)row.size() * (ll)col.size();

    for(const auto &d : d1) {
        set<pll> com;
        for(const auto &r : row) {
            if(inBounds({r, r - d}, n)) com.insert({r, r - d});
        }
        for(const auto &c : col) {
            if(inBounds({c + d, c}, n)) com.insert({c + d, c});
        }
        ans -= n - abs(d);
        ans += (ll)com.size();
    }

    for(const auto &d : d2) {
        set<pll> com;
        for(const auto &r : row) {
            if(inBounds({r, d - r}, n)) com.insert({r, d - r});
        }
        for(const auto &c : col) {
            if(inBounds({d - c, c}, n)) com.insert({d - c, c});
        }
        for(const auto &od : d1) {
            ll x = ((d % 2) + 2) % 2;
            ll y = ((od % 2) + 2) % 2;
            if(x != y) continue;
            if(inBounds({(d + od) / 2, (d - od) / 2}, n)) com.insert({(d + od) / 2, (d - od) / 2});
        }
        ans -= d < n ? (d - 1) : (2 * n - d + 1);
        ans += (ll)com.size();
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}