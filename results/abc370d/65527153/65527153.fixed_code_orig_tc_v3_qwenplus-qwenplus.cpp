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
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(W + 1), col(H + 1);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row[C].find(R) == row[C].end()) {
            // No wall at (R, C), so destroy walls in four directions

            // Up and Down
            auto& r_set = row[C];
            auto it = r_set.lower_bound(R);
            if (it != r_set.end()) {
                int del = *it;
                col[del].erase(C);
                r_set.erase(it);
            }
            if (it != r_set.begin()) {
                --it;
                int del = *it;
                col[del].erase(C);
                r_set.erase(it);
            }

            // Left and Right
            auto& c_set = col[R];
            it = c_set.lower_bound(C);
            if (it != c_set.end()) {
                int del = *it;
                row[del].erase(R);
                c_set.erase(it);
            }
            if (it != c_set.begin()) {
                --it;
                int del = *it;
                row[del].erase(R);
                c_set.erase(it);
            }
        } else {
            // There is a wall at (R, C), remove it
            row[C].erase(R);
            col[R].erase(C);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += col[i].size();
    }
    cout << ans << '\n';

    return 0;
}