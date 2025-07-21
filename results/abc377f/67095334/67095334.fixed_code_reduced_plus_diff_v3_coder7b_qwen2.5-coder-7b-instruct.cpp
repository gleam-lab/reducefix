#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e9;

ll n, m;
set<ll> hor, ver, diag1, diag2;

void solve() {
    cin >> n >> m;
    for (ll i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        hor.insert(x), ver.insert(y), diag1.insert(x + y), diag2.insert(x - y);
    }

    ll ans = (n - hor.size()) * (n - ver.size());
    for (auto& d : diag1) {
        set<ll> s;
        for (auto& x : hor) if (x + (d - x) <= n) s.insert(x);
        for (auto& y : ver) if (d - y >= 1) s.insert(d - y);
        ans -= (d <= n + 1 ? d - 1 : n - (d - n)) - s.size();
    }
    for (auto& d : diag2) {
        set<ll> s;
        for (auto& x : hor) if (x - (d + x) >= 1) s.insert(x);
        for (auto& y : ver) if (d + y <= n) s.insert(d + y);
        for (auto& e : diag1) if ((e + d) % 2 == 0 && (e - d) % 2 == 0) {
            ll si = (e + d) / 2, sj = (e - d) / 2;
            if (si >= 2 && si <= n && sj >= 1 && sj <= n) s.insert(si);
        }
        ans -= (d >= 0 ? n - (1 - d) : n - d) - s.size();
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}