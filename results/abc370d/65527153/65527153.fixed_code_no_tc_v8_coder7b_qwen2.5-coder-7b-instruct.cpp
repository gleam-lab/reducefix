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
            st1[i].emplace(j);
            st2[j].emplace(i);
        }
    }

    auto erase = [&](int r, int c) -> void {
        st1[r].erase(c);
        st2[c].erase(r);
    };

    auto lowerBound = [](auto& s, int val) -> auto {
        auto it = s.lower_bound(val);
        if (it == s.end() || *it > val) it--;
        return it;
    };

    while (q--) {
        int r, c; cin >> r >> c;
        if (st1[r].count(c)) {
            erase(r, c);
            continue;
        }

        // Find the smallest index greater than c in the same row
        auto it = lowerBound(st1[r], c);
        if (it != st1[r].end()) {
            erase(r, *it);
        }

        // Find the largest index less than c in the same row
        if (it != st1[r].begin()) {
            it--;
            erase(r, *it);
        }

        // Find the smallest index greater than r in the same column
        it = lowerBound(st2[c], r);
        if (it != st2[c].end()) {
            erase(*it, c);
        }

        // Find the largest index less than r in the same column
        if (it != st2[c].begin()) {
            it--;
            erase(*it, c);
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