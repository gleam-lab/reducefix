#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<int>> sink(h, vector<int>(w, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = height[i][j];
                pq.push({height[i][j], {i, j}});
            }
        }
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    while (!pq.empty()) {
        auto [H, p] = pq.top();
        auto [r, c] = p;
        pq.pop();
        if (visited[r][c]) continue;
        visited[r][c] = true;

        for (int i = 0; i < 4; ++i) {
            int nr = r + di[i][0];
            int nc = c + di[i][1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            int &neighborHeight = height[nr][nc];
            int newSinkLevel = min(H, neighborHeight);
            if (sink[nr][nc] > newSinkLevel) {
                sink[nr][nc] = newSinkLevel;
                pq.push({newSinkLevel, {nr, nc}});
            }
        }
    }

    vector<int> count(y + 2, 0); // count[y]: number of cells that sink at exactly year y

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int sinkYear = sink[i][j];
            if (sinkYear <= y) {
                count[sinkYear]++;
            }
        }
    }

    // prefix sum up to each year
    vector<ll> areaRemaining(y + 2, 0);
    ll totalArea = (ll)h * w;
    ll sunkSoFar = 0;
    for (int year = 1; year <= y; ++year) {
        sunkSoFar += count[year];
        areaRemaining[year] = totalArea - sunkSoFar;
    }

    for (int year = 1; year <= y; ++year) {
        cout << areaRemaining[year] << "\n";
    }

    return 0;
}