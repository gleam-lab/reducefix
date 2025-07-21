#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(),x.end()

const int N = 400020, INF = 0x3f3f3f3f;
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

    while (q--) {
        int r, c; cin >> r >> c;
        if (!st1[r].empty() && *st1[r].begin() == c) {
            erase(r, c);
            continue;
        }

        auto it = st1[r].lower_bound(c);
        if (it != st1[r].end() && *it == c) {
            erase(r, *it);
        } else if (it != st1[r].begin()) {
            it--;
            erase(r, *it);
        }

        it = st2[c].lower_bound(r);
        if (it != st2[c].end() && *it == r) {
            erase(*it, c);
        } else if (it != st2[c].begin()) {
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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}