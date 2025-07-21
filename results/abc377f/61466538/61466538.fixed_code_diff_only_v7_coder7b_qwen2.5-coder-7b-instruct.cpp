#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e3 + 5;

int n, m;
vector<pii> q;
set<int> row, col, d1, d2;

bool inBounds(const pll &a, const ll n) {
    return 1 <= a.fst && a.fst <= n && 1 <= a.snd && a.snd <= n;
}

void solve() {
    cin >> n >> m;
    q.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> q[i].first >> q[i].second;
        row.insert(q[i].first);
        col.insert(q[i].second);
        d1.insert(q[i].first - q[i].second);
        d2.insert(q[i].first + q[i].second);
    }

    ll ans = n * n;
    ans -= 1LL * row.size() * n;
    ans -= 1LL * col.size() * n;
    ans += 1LL * row.size() * col.size();

    set<pll> com;
    for(auto &d : d1) {
        com.clear();
        for(auto &r : row) {
            if(inBounds({r, r - d}, n)) com.insert({r, r - d});
        }
        for(auto &c : col) {
            if(inBounds({c + d, c}, n)) com.insert({c + d, c});
        }
        ans -= n - abs(d);
        ans += com.size();
    }

    for(auto &d : d2) {
        com.clear();
        for(auto &r : row) {
            if(inBounds({r, d - r}, n)) com.insert({r, d - r});
        }
        for(auto &c : col) {
            if(inBounds({d - c, c}, n)) com.insert({d - c, c});
        }
        for(auto &od : d1) {
            if(((d % 2) + (od % 2)) == 1) continue;
            ll x = (d + od) / 2;
            ll y = (d - od) / 2;
            if(inBounds({x, y}, n)) com.insert({x, y});
        }
        ans -= d < n ? (d - 1) : (2 * n - d + 1);
        ans += com.size();
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}