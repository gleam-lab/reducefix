#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define pll pair<ll, ll>
#define priority_queue_less priority_queue<ll, vector<ll>, less<ll>>
#define priority_queue_greater priority_queue<ll, vector<ll>, greater<ll>>

const ll dx[] = {1, -1, 0, 0};
const ll dy[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll h, w, y;
    cin >> h >> w >> y;
    
    vvl grid(h, vl(w));
    ll total = h * w;

    ll max_val = 0;
    rep(i,h) rep(j,w) {
        cin >> grid[i][j];
        max_val = max(max_val, grid[i][j]);
    }

    // To store which cells are still above sea level
    vvb alive(h, vb(w, true));

    // Create a map of elevation -> list of coordinates with that elevation
    map<ll, vector<pll>> elev_map;
    rep(i,h) rep(j,w) {
        elev_map[grid[i][j]].push_back({i, j});
    }

    // Initialize boundaries (edge cells)
    vvb is_boundary(h, vb(w, false));
    rep(i,h) {
        is_boundary[i][0] = true;
        is_boundary[i][w-1] = true;
    }
    rep(j,w) {
        is_boundary[0][j] = true;
        is_boundary[h-1][j] = true;
    }

    // For each cell, track if it's connected to the boundary
    vvb connected_to_boundary(h, vb(w, false));

    // Queue for BFS
    queue<pll> q;

    // Initialize BFS from all boundary cells
    rep(i,h) rep(j,w) {
        if (is_boundary[i][j]) {
            q.push({i, j});
            connected_to_boundary[i][j] = true;
        }
    }

    // Process in order of increasing elevation
    ll removed = 0;

    for (ll year = 1; year <= y; ++year) {
        // Add new cells that become connected to boundary this year
        auto it = elev_map.find(year);
        if (it != elev_map.end()) {
            for (auto [i, j] : it->second) {
                if (!alive[i][j]) continue;  // already sunk
                // Check if this cell is now connected to boundary
                rep(d,4) {
                    ll ni = i + dx[d], nj = j + dy[d];
                    if (0 <= ni && ni < h && 0 <= nj && nj < w && connected_to_boundary[ni][nj]) {
                        q.push({i, j});
                        connected_to_boundary[i][j] = true;
                        break;
                    }
                }
            }
        }

        // Run BFS to find all cells that sink this year
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if (!alive[i][j] || grid[i][j] > year) continue;
            
            alive[i][j] = false;
            removed++;

            rep(d,4) {
                ll ni = i + dx[d], nj = j + dy[d];
                if (0 <= ni && ni < h && 0 <= nj && nj < w && alive[ni][nj] && grid[ni][nj] <= year) {
                    q.push({ni, nj});
                    connected_to_boundary[ni][nj] = true;
                }
            }
        }

        cout << total - removed << "\n";
    }
}