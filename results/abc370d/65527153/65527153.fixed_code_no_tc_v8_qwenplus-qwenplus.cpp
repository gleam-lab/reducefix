#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define pb push_back

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row and column, maintain a set of wall positions that are still intact
    vector<set<int>> rows(H + 1), cols(W + 1);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    auto destroy = [&](int r, int c) {
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
        }
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (rows[r].count(c)) {
            // Bomb placed on an intact wall: destroy it only
            destroy(r, c);
            continue;
        }

        // Look right in row r
        auto it = rows[r].lower_bound(c);
        if (it != rows[r].end()) {
            destroy(r, *it);
        }

        // Look left in row r
        it = rows[r].lower_bound(c);
        if (it != rows[r].begin()) {
            --it;
            destroy(r, *it);
        }

        // Look down in column c
        auto jt = cols[c].lower_bound(r);
        if (jt != cols[c].end()) {
            destroy(*jt, c);
        }

        // Look up in column c
        jt = cols[c].lower_bound(r);
        if (jt != cols[c].begin()) {
            --jt;
            destroy(*jt, c);
        }
    }

    long long remaining = 0;
    for (int i = 1; i <= H; ++i) {
        remaining += rows[i].size();
    }
    cout << remaining << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}