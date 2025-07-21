#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Directions for moving up, down, left, right
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    auto isValid = [&](int x, int y) {
        return x >= 0 && x < H && y >= 0 && y < W && !visited[x][y];
    };

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W-1], make_pair(i, W-1));
        visited[i][0] = true;
        visited[i][W-1] = true;
    }
    for (int j = 1; j < W-1; ++j) {
        pq.emplace(A[0][j], make_pair(0, j));
        pq.emplace(A[H-1][j], make_pair(H-1, j));
        visited[0][j] = true;
        visited[H-1][j] = true;
    }

    int totalArea = H * W;

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto [height, pos] = pq.top();
            pq.pop();
            --totalArea;
            
            for (auto& dir : directions) {
                int newX = pos.first + dir.first;
                int newY = pos.second + dir.second;
                if (isValid(newX, newY)) {
                    visited[newX][newY] = true;
                    pq.emplace(A[newX][newY], make_pair(newX, newY));
                }
            }
        }
        cout << totalArea << endl;
    }

    return 0;
}