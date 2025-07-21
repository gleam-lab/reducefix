#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); ++i)
#define all(x) x.begin(), x.end()

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : false); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : false); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(W), col(H);
    rep(i, H) rep(j, W) {
        row[j].insert(i);
        col[i].insert(j);
    }

    ll total = (ll)H * W;

    rep(_, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // Try to erase the current cell first
        if (col[R].count(C)) {
            col[R].erase(C);
            row[C].erase(R);
            --total;
            continue;
        }

        // Up
        auto it = row[C].lower_bound(R);
        if (it != row[C].begin()) {
            --it;
            int r = *it;
            col[r].erase(C);
            row[C].erase(r);
            --total;
        }

        // Down
        it = row[C].lower_bound(R);
        if (it != row[C].end()) {
            int r = *it;
            col[r].erase(C);
            row[C].erase(r);
            --total;
        }

        // Left
        it = col[R].lower_bound(C);
        if (it != col[R].begin()) {
            --it;
            int c = *it;
            row[c].erase(R);
            col[R].erase(c);
            --total;
        }

        // Right
        it = col[R].lower_bound(C);
        if (it != col[R].end()) {
            int c = *it;
            row[c].erase(R);
            col[R].erase(c);
            --total;
        }
    }

    cout << total << '\n';
}