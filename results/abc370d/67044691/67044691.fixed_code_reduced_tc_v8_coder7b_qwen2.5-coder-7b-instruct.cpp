#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const ll inf = (1LL << 61);

int main() {
    ll h, w, q; cin >> h >> w >> q;
    vector<vi> grid(h, vi(w, 1)); // Initialize grid with all cells having a wall
    map<pair<ll, ll>, bool> visited; // To keep track of visited cells

    while (q--) {
        ll r, c; cin >> r >> c;
        r--, c--;

        if (grid[r][c] == 0) continue; // Skip if the cell already has no wall

        queue<pair<ll, ll>> q;
        q.push({r, c});
        visited[{r, c}] = true;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            // Check and remove walls in the same row and column as the current cell
            for (int i = 0; i < w; ++i) {
                if (y != i && grid[x][i]) {
                    grid[x][i] = 0;
                    if (!visited[{x, i}]) {
                        q.push({x, i});
                        visited[{x, i}] = true;
                    }
                }
            }
            for (int i = 0; i < h; ++i) {
                if (x != i && grid[i][y]) {
                    grid[i][y] = 0;
                    if (!visited[{i, y}]) {
                        q.push({i, y});
                        visited[{i, y}] = true;
                    }
                }
            }
        }
    }

    ll count = 0;
    rep(i, h) rep(j, w) if (grid[i][j]) count++;

    cout << count << endl;
}