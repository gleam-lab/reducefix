#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(),x.end()

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row(H + 1), col(W + 1);

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    auto erase = [&](int r, int c) {
        row[r].erase(c);
        col[c].erase(r);
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;
        if (row[r].count(c)) {
            erase(r, c);
            continue;
        }

        auto it = row[r].lower_bound(c);
        if (it != row[r].end()) {
            erase(r, *it);
        }
        it = row[r].lower_bound(c);
        if (it != row[r].begin()) {
            --it;
            erase(r, *it);
        }

        auto it2 = col[c].lower_bound(r);
        if (it2 != col[c].end()) {
            erase(*it2, c);
        }
        it2 = col[c].lower_bound(r);
        if (it2 != col[c].begin()) {
            --it2;
            erase(*it2, c);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += row[i].size();
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}