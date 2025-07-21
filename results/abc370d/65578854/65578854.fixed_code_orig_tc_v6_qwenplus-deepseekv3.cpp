#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> rows(H + 1), cols(W + 1);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    ll total = (ll)H * W;
    ll destroyed = 0;

    while (Q--) {
        int R, C;
        cin >> R >> C;
        if (rows[R].count(C)) {
            rows[R].erase(C);
            cols[C].erase(R);
            destroyed++;
        } else {
            // Check up
            auto it = cols[C].lower_bound(R);
            if (it != cols[C].begin()) {
                --it;
                int r = *it;
                if (rows[r].count(C)) {
                    rows[r].erase(C);
                    cols[C].erase(r);
                    destroyed++;
                }
            }
            // Check down
            it = cols[C].lower_bound(R);
            if (it != cols[C].end()) {
                int r = *it;
                if (rows[r].count(C)) {
                    rows[r].erase(C);
                    cols[C].erase(r);
                    destroyed++;
                }
            }
            // Check left
            it = rows[R].lower_bound(C);
            if (it != rows[R].begin()) {
                --it;
                int c = *it;
                if (cols[c].count(R)) {
                    cols[c].erase(R);
                    rows[R].erase(c);
                    destroyed++;
                }
            }
            // Check right
            it = rows[R].lower_bound(C);
            if (it != rows[R].end()) {
                int c = *it;
                if (cols[c].count(R)) {
                    cols[c].erase(R);
                    rows[R].erase(c);
                    destroyed++;
                }
            }
        }
    }
    cout << total - destroyed << endl;
    return 0;
}