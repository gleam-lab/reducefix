#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
vector<int> X[MAXN], Y[MAXN];

void erase(int r, int c) {
    X[r].erase(find(X[r].begin(), X[r].end(), c));
    Y[c].erase(find(Y[c].begin(), Y[c].end(), r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    for (int i = 0; i < H; ++i) X[i] = vector<int>(W);
    for (int i = 0; i < W; ++i) Y[i] = vector<int>(H);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            X[i].push_back(j);
            Y[j].push_back(i);
        }
    }

    int ans = H * W;
    while (Q--) {
        int R, C;
        cin >> R >> C;
        --R, --C;

        if (find(X[R].begin(), X[R].end(), C) == X[R].end()) {
            for (auto it = upper_bound(Y[C].begin(), Y[C].end(), R); it != Y[C].end(); ++it) {
                if (*it > R) {
                    erase(*it, C);
                    break;
                }
            }
            for (auto it = lower_bound(Y[C].rbegin(), Y[C].rend(), R); it != Y[C].rend(); ++it) {
                if (*it < R) {
                    erase(*it, C);
                    break;
                }
            }
            for (auto it = upper_bound(X[R].begin(), X[R].end(), C); it != X[R].end(); ++it) {
                if (*it > C) {
                    erase(R, *it);
                    break;
                }
            }
            for (auto it = lower_bound(X[R].rbegin(), X[R].rend(), C); it != X[R].rend(); ++it) {
                if (*it < C) {
                    erase(R, *it);
                    break;
                }
            }
        } else {
            erase(R, C);
        }
    }

    cout << ans - (X[0].size() + Y[0].size()) << '\n';
    return 0;
}