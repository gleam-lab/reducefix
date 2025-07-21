#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for(int i = 1; i < (int)(n); ++i)
#define rrep(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define rrep1(i, n) for(int i = (int)(n) - 1; i >= 1; --i)

using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvvll>;

using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;

using vs = vector<string>;

ll H, W, Q;

ll wallsremaining[400010];

bool is_wall(ll r, ll c) {
    if (r < 1 || r > H || c < 1 || c > W) return false;
    return wallsremaining[r * W + c];
}

void destroy_wall(ll r, ll c) {
    wallsremaining[r * W + c] = 0;
}

void destroy_walls(ll r, ll c) {
    // Horizontal walls
    ll left = c;
    while (left > 1 && is_wall(r, left - 1)) {
        destroy_wall(r, left - 1);
        --left;
    }
    ll right = c;
    while (right < W && is_wall(r, right + 1)) {
        destroy_wall(r, right + 1);
        ++right;
    }

    // Vertical walls
    ll up = r;
    while (up > 1 && is_wall(up - 1, c)) {
        destroy_wall(up - 1, c);
        --up;
    }
    ll down = r;
    while (down < H && is_wall(down + 1, c)) {
        destroy_wall(down + 1, c);
        ++down;
    }
}

int main() {
    cin >> H >> W >> Q;
    rep(i, H * W) wallsremaining[i] = 1;

    while (Q--) {
        ll r, c;
        cin >> r >> c;
        if (is_wall(r, c)) {
            destroy_wall(r, c);
        } else {
            destroy_walls(r, c);
        }
    }

    ll remaining = 0;
    rep(i, H) {
        rep(j, W) {
            remaining += is_wall(i + 1, j + 1);
        }
    }

    cout << remaining << endl;
    return 0;
}