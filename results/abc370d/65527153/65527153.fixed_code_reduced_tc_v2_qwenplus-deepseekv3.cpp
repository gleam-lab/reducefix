#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(),x.end()
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

    auto erase = [&](int r, int c) {
        row[r].erase(c);
        col[c].erase(r);
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        if (row[R].count(C)) {
            erase(R, C);
        } else {
            // Check left
            auto it_left = row[R].lower_bound(C);
            if (it_left != row[R].begin()) {
                --it_left;
                erase(R, *it_left);
            }
            // Check right
            auto it_right = row[R].upper_bound(C);
            if (it_right != row[R].end()) {
                erase(R, *it_right);
            }
            // Check up
            auto it_up = col[C].lower_bound(R);
            if (it_up != col[C].begin()) {
                --it_up;
                erase(*it_up, C);
            }
            // Check down
            auto it_down = col[C].upper_bound(R);
            if (it_down != col[C].end()) {
                erase(*it_down, C);
            }
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