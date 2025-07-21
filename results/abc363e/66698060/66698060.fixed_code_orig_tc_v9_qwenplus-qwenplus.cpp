#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    vector<vector<ll>> A(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }

    // Create a visited matrix
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Min-heap priority queue: stores {height, row, col}
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

    // Initialize the queue with border cells
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }

    // Total area of the island
    ll total_area = h * w;

    // We will store the results in a vector and print them at the end
    vector<ll> result(y + 2); // result[year] = remaining area

    // Process the events in order of increasing sea level
    for (ll year = 1; year <= y; ++year) {
        while (!pq.empty() && pq.top()[0] <= year) {
            ll x = pq.top()[1];
            ll y_coord = pq.top()[2];
            pq.pop();

            if (!visited[x][y_coord]) {
                visited[x][y_coord] = true;
                total_area--;

                // Push adjacent cells into the queue if not visited
                for (ll d = 0; d < 4; ++d) {
                    ll nx = x + dx[d];
                    ll ny = y_coord + dy[d];
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                        pq.push({A[nx][ny], nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        result[year] = total_area;
    }

    // Output results
    for (ll i = 1; i <= y; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}