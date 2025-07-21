#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row(H + 2); // 1-based to H
    vector<set<int>> col(W + 2); // 1-based to W
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    ll ans = (ll)H * W;
    ll destroyed = 0;

    while (Q--) {
        int R, C;
        cin >> R >> C;
        if (row[R].count(C)) {
            row[R].erase(C);
            col[C].erase(R);
            destroyed++;
            continue;
        }
        // Up
        auto it = col[C].lower_bound(R);
        if (it != col[C].begin()) {
            --it;
            int r = *it;
            if (row[r].count(C)) {
                row[r].erase(C);
                col[C].erase(r);
                destroyed++;
            }
        }
        // Down
        it = col[C].lower_bound(R);
        if (it != col[C].end()) {
            int r = *it;
            if (row[r].count(C)) {
                row[r].erase(C);
                col[C].erase(r);
                destroyed++;
            }
        }
        // Left
        it = row[R].lower_bound(C);
        if (it != row[R].begin()) {
            --it;
            int c = *it;
            if (col[c].count(R)) {
                col[c].erase(R);
                row[R].erase(c);
                destroyed++;
            }
        }
        // Right
        it = row[R].lower_bound(C);
        if (it != row[R].end()) {
            int c = *it;
            if (col[c].count(R)) {
                col[c].erase(R);
                row[R].erase(c);
                destroyed++;
            }
        }
    }
    cout << ans - destroyed << '\n';
    return 0;
}