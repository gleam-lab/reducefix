#ifndef LOCAL
#pragma optimize(2)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define zjj master
const int N = 200020, INF = 0x3f3f3f3f;
int n, m;

void solve()
{
    int q;
    cin >> n >> m >> q;
    vector<set<int>> st1(n + 1), st2(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            st1[i].insert(j);
            st2[j].insert(i);
        }
    }

    auto erase = [&](int r, int c) -> void {
        st1[r].erase(c);
        st2[c].erase(r);
    };

    while (q--) {
        int r, c; cin >> r >> c;
        if (st1[r].count(c)) {
            erase(r, c);
            continue;
        }

        // Left
        auto it_left = st1[r].lower_bound(c);
        if (it_left != st1[r].begin()) {
            --it_left;
            erase(r, *it_left);
        }

        // Right
        auto it_right = st1[r].upper_bound(c);
        if (it_right != st1[r].end()) {
            erase(r, *it_right);
        }

        // Up
        auto it_up = st2[c].lower_bound(r);
        if (it_up != st2[c].begin()) {
            --it_up;
            erase(*it_up, c);
        }

        // Down
        auto it_down = st2[c].upper_bound(r);
        if (it_down != st2[c].end()) {
            erase(*it_down, c);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += st1[i].size();
    cout << ans << "\n";
}

signed main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}