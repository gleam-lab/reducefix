#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
using ll = long long;
const int INF = 1e9;

struct Cell {
    bool operator<(const Cell &c) const {
        if (r != c.r) return r < c.r;
        return c < c.c;
    }
    int r, c;
};

template<typename T>
void UNIQUE(vector<T> &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    map<int, set<int>> rowWalls, colWalls;
    for (int i = 1; i <= H; ++i) {
        set<int> s;
        for (int j = 1; j <= W; ++j) s.insert(j);
        rowWalls[i] = s;
    }
    for (int i = 1; i <= W; ++i) {
        set<int> s;
        for (int j = 1; j <= H; ++j) s.insert(j);
        colWalls[i] = s;
    }

    auto remove = [&](int r, int c) {
        rowWalls[r].erase(c);
        colWalls[c].erase(r);
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        if (rowWalls[R].count(C)) {
            // Already destroyed
            continue;
        } else {
            // Destroy the first walls in four directions
            // Up
            if (!colWalls[C].empty() && *colWalls[C].lower_bound(R) == R) {
                int x = R;
                while (colWalls[C].count(x) == 0 && x > 1) x--;
                if (x >= 1 && colWalls[C].count(x)) {
                    remove(x, C);
                }
            }
            // Down
            {
                int x = R + 1;
                while (x <= H && !colWalls[C].count(x)) x++;
                if (x <= H) {
                    remove(x, C);
                }
            }
            // Left
            {
                int x = C - 1;
                while (x >= 1 && !rowWalls[R].count(x)) x--;
                if (x >= 1) {
                    remove(R, x);
                }
            }
            // Right
            {
                int x = C + 1;
                while (x <= W && !rowWalls[R].count(x)) x++;
                if (x <= W) {
                    remove(R, x);
                }
            }
        }
    }

    ll ans = 0;
    for (auto &[_, s] : rowWalls) {
        ans += s.size();
    }
    cout << ans << endl;

    return 0;
}