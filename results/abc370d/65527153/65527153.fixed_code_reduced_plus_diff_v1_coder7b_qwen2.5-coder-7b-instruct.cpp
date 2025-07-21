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

const int N = 4e5 + 10, INF = 0x3f3f3f3f;
int n, m, q;
vector<vector<int>> g(N, vector<int>(N));

void solve() {
    cin >> n >> m >> q;
    
    // Initialize the grid
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            g[i][j] = 1; // Initially, every cell has a wall
        }
    }

    auto destroyWall = [&](int r, int c) -> void {
        if (g[r][c]) { // If there is a wall
            g[r][c] = 0; // Destroy the wall
            return;
        }
        
        // Find the nearest wall above the current position
        for (int i = r - 1; i >= 1; --i) {
            if (g[i][c]) {
                g[i][c] = 0; // Destroy the found wall
                break;
            }
        }
        
        // Find the nearest wall below the current position
        for (int i = r + 1; i <= n; ++i) {
            if (g[i][c]) {
                g[i][c] = 0; // Destroy the found wall
                break;
            }
        }
        
        // Find the nearest wall to the left of the current position
        for (int j = c - 1; j >= 1; --j) {
            if (g[r][j]) {
                g[r][j] = 0; // Destroy the found wall
                break;
            }
        }
        
        // Find the nearest wall to the right of the current position
        for (int j = c + 1; j <= m; ++j) {
            if (g[r][j]) {
                g[r][j] = 0; // Destroy the found wall
                break;
            }
        }
    };

    while (q--) {
        int r, c; cin >> r >> c;
        destroyWall(r, c);
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans += g[i][j]; // Count the remaining walls
        }
    }
    
    cout << ans << "\n";
}

signed main() {
#ifdef LOCAL
    freopen("in.in", "r", stdin);freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}