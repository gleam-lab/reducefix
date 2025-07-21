#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
vector<vector<int>> A(MAXN, vector<int>(MAXN));
vector<vector<bool>> used(MAXN, vector<bool>(MAXN));

bool isValid(int y, int x) {
    return y >= 0 && y < H && x >= 0 && x < W;
}

void bfs(int sea_level) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] <= sea_level) {
                pq.emplace(A[i][j], make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }

    while (!pq.empty()) {
        auto [height, pos] = pq.top();
        pq.pop();
        
        static const int dx[] = {0, 0, -1, 1};
        static const int dy[] = {-1, 1, 0, 0};
        
        for (int k = 0; k < 4; ++k) {
            int ny = pos.first + dy[k];
            int nx = pos.second + dx[k];
            
            if (isValid(ny, nx) && !visited[ny][nx] && A[ny][nx] <= sea_level) {
                pq.emplace(A[ny][nx], make_pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        bfs(sea_level);
        int remaining_area = H * W - count_if(all(used), [](const auto& row) { return accumulate(all(row), 0); });
        cout << remaining_area << endl;
    }

    return 0;
}