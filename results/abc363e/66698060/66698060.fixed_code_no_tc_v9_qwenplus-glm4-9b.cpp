#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

struct Cell {
    ll elevation, x, y;
    Cell(ll el, ll x, ll y) : elevation(el), x(x), y(y) {}
};

bool compare(Cell a, Cell b, ll year) {
    return a.elevation > year || b.elevation > year;
}

int main() {
    ll h, w, y; cin >> h >> w >> y;
    vector<vector<ll>> island(h, vector<ll>(w));
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> island[i][j];
        }
    }

    priority_queue<Cell, vector<Cell>, decltype(compare)> pq(compare);
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Initialize the queue with the edges of the island
    for (ll i = 0; i < h; i++) {
        pq.push(Cell(island[i][0], i, 0));
        pq.push(Cell(island[i][w - 1], i, w - 1));
        visited[i][0] = visited[i][w - 1] = true;
    }
    for (ll j = 0; j < w; j++) {
        pq.push(Cell(island[0][j], 0, j));
        pq.push(Cell(island[h - 1][j], h - 1, j));
        visited[0][j] = visited[h - 1][j] = true;
    }

    ll remaining_area = h * w;

    for (ll year = 1; year <= y; year++) {
        while (!pq.empty() && pq.top().elevation <= year) {
            Cell c = pq.top(); pq.pop();
            remaining_area -= 1;

            for (ll k = 0; k < 4; k++) {
                ll nexi = c.x + dx[k], nexj = c.y + dy[k];
                if (0 <= nexi && nexi < h && 0 <= nexj && nexj < w && !visited[nexi][nexj] && island[nexi][nexj] > year) {
                    pq.push(Cell(island[nexi][nexj], nexi, nexj));
                    visited[nexi][nexj] = true;
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}