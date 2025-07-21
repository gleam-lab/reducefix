#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(v) v.begin(), v.end()

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    vector<vector<ll>> A(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> A[i][j];

    // Find the initial number of cells that are adjacent to the sea
    // or will sink at year 1
    queue<pair<ll, ll>> q;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    bool will_sink[H][W];
    memset(will_sink, false, sizeof(will_sink));
    ll initial_count = 0;

    rep(i, h) {
        rep(j, w) {
            // If the cell is adjacent to the sea or will sink at year 1
            if ((i == 0 || j == 0 || j == w - 1 || i == h - 1) || (A[i][j] <= 1)) {
                will_sink[i][j] = true;
                initial_count++;
            }
        }
    }

    // BFS to propagate sinking effect
    q.push({0, 0}); // Starting from the sea
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            ll ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni][nj] && !will_sink[ni][nj] && A[ni][nj] <= 1) {
                visited[ni][nj] = true;
                will_sink[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }

    // The area of the island that remains above sea level
    ll remaining_area = h * w - initial_count;

    // Output the area for each year
    for (ll year = 1; year <= y; year++) {
        // Each year, the area remains the same, as the sinking process
        // is already accounted for in the initial count
        cout << remaining_area << endl;
    }

    return 0;
}