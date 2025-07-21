#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll H, W, Q;
    cin >> H >> W >> Q;

    // row[i]: set of columns with walls in row i
    vector<set<ll>> row(H), col(W);
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (Q--) {
        ll R, C;
        cin >> R >> C;
        R--; C--;

        if (row[R].count(C)) {
            // Wall exists here, just remove it
            row[R].erase(C);
            col[C].erase(R);
        } else {
            // Find the nearest walls in each direction
            array<array<ll, 2>, 4> to_remove;
            // Up
            auto it_up = col[C].lower_bound(R);
            if (it_up != col[C].begin()) {
                --it_up;
                to_remove[0] = {*it_up, C};
            } else {
                to_remove[0] = {-1, -1}; // No wall above
            }

            // Down
            auto it_down = col[C].upper_bound(R);
            if (it_down != col[C].end()) {
                to_remove[1] = {*it_down, C};
            } else {
                to_remove[1] = {-1, -1};
            }

            // Left
            auto it_left = row[R].lower_bound(C);
            if (it_left != row[R].begin()) {
                --it_left;
                to_remove[2] = {R, *it_left};
            } else {
                to_remove[2] = {-1, -1};
            }

            // Right
            auto it_right = row[R].upper_bound(C);
            if (it_right != row[R].end()) {
                to_remove[3] = {R, *it_right};
            } else {
                to_remove[3] = {-1, -1};
            }

            // Remove them all
            for (const auto& p : to_remove) {
                if (p[0] == -1 || p[1] == -1)
                    continue;
                row[p[0]].erase(p[1]);
                col[p[1]].erase(p[0]);
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < H; ++i) {
        ans += row[i].size();
    }
    cout << ans << "\n";
}