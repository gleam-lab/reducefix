#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> X(H), Y(W);
    // Initialize the walls
    rep(i, H) rep(j, W) {
        X[i].insert(j);
        Y[j].insert(i);
    }
    ll ans = 2 * H * W - 4; // Initial walls count, minus 4 as no walls between adjacent cells
    rep(itr, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--; // Convert to 0-based index
        // Check if there's a wall at the given cell
        if (!X[R].count(C)) {
            // If not, destroy walls adjacent to the given cell
            // Destroy horizontal walls
            auto it = Y[C].lower_bound(R);
            if (it != Y[C].end()) {
                Y[C].erase(it);
                ans -= 2;
            }
            // Destroy vertical walls
            it = X[R].lower_bound(C);
            if (it != X[R].end()) {
                X[R].erase(it);
                ans -= 2;
            }
        } else {
            // If there's a wall, destroy it and no adjacent walls need destruction
            ans -= 1;
            X[R].erase(C);
            Y[C].erase(R);
        }
    }
    cout << ans << endl;
    return 0;
}