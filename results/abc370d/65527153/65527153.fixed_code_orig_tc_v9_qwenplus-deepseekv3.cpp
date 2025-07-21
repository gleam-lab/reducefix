#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(), x.end()
const int N = 200020, INF = 0x3f3f3f3f;

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

    while (Q--) {
        int R, C;
        cin >> R >> C;
        if (row[R].count(C)) {
            row[R].erase(C);
            col[C].erase(R);
            continue;
        }

        // Up
        auto it = col[C].lower_bound(R);
        if (it != col[C].begin()) {
            --it;
            int r = *it;
            row[r].erase(C);
            col[C].erase(r);
        }

        // Down
        it = col[C].upper_bound(R);
        if (it != col[C].end()) {
            int r = *it;
            row[r].erase(C);
            col[C].erase(r);
        }

        // Left
        it = row[R].lower_bound(C);
        if (it != row[R].begin()) {
            --it;
            int c = *it;
            row[R].erase(c);
            col[c].erase(R);
        }

        // Right
        it = row[R].upper_bound(C);
        if (it != row[R].end()) {
            int c = *it;
            row[R].erase(c);
            col[c].erase(R);
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
    int T = 1;
    while (T--) solve();
    return 0;
}