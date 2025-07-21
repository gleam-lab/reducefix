#include <bits/stdc++.h>
using namespace std;

struct Init { 
    Init() { 
        ios::sync_with_stdio(false); 
        cin.tie(nullptr); 
        cout << fixed << setprecision(12); 
    } 
} init;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Push all border sections into the priority queue
    for (int i = 0; i < H; ++i) {
        if (!visited[i][0]) {
            pq.emplace(A[i][0], i, 0);
            visited[i][0] = true;
        }
        if (!visited[i][W-1]) {
            pq.emplace(A[i][W-1], i, W-1);
            visited[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (!visited[0][j]) {
            pq.emplace(A[0][j], 0, j);
            visited[0][j] = true;
        }
        if (!visited[H-1][j]) {
            pq.emplace(A[H-1][j], H-1, j);
            visited[H-1][j] = true;
        }
    }

    int ans = H * W;
    vector<int> res(Y + 1, ans); // res[i] is the answer for year i
    int current_year = 1;
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};

    while (!pq.empty() && current_year <= Y) {
        auto [elev, i, j] = pq.top();
        if (elev > current_year) {
            res[current_year] = ans;
            ++current_year;
            continue;
        }
        pq.pop();
        --ans;
        res[current_year] = ans;
        for (int d = 0; d < 4; ++d) {
            int ni = i + dy[d];
            int nj = j + dx[d];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                visited[ni][nj] = true;
                pq.emplace(A[ni][nj], ni, nj);
            }
        }
    }

    // Fill remaining years if the sea level hasn't reached all sections yet
    for (int y = current_year + 1; y <= Y; ++y) {
        res[y] = ans;
    }

    for (int y = 1; y <= Y; ++y) {
        cout << res[y] << '\n';
    }

    return 0;
}