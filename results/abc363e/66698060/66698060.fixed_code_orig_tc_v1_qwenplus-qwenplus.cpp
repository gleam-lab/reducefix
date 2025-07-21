#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    vector<vector<ll>> A(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i)
        for (ll j = 0; j < w; ++j)
            cin >> A[i][j];

    // We'll use a max-heap to process cells in decreasing order of elevation
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Initialize the perimeter with all border cells
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.emplace(A[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    // We process the heap and simulate the erosion from the outside in
    vector<ll> remaining(y + 2); // remaining[y] is for year y
    remaining[0] = h * w;

    // We'll store how many cells sink at each elevation level
    map<ll, ll> sink_count;

    while (!pq.empty()) {
        auto [elev, x, y] = pq.top();
        pq.pop();

        // Count this cell sinking
        sink_count[elev]++;

        for (ll d = 0; d < 4; ++d) {
            ll nx = x + dx[d];
            ll ny = y + dy[d];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // Now compute cumulative area remaining for each year
    ll total_sunk = 0;
    auto it = sink_count.begin();
    for (ll year = 1; year <= y; ++year) {
        // Add all cells that sink at elevation <= year
        while (it != sink_count.end() && it->first < year) {
            total_sunk += it->second;
            ++it;
        }
        cout << (h * w - total_sunk) << endl;
    }
}