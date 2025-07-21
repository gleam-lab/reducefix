#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, pair<long long, long long>> pllp;

vector<vector<long long>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(vector<vector<long long>>& heights, vector<vector<bool>>& visited, long long& area, long long targetHeight) {
    queue<pair<long long, long long>> q;
    for (long long i = 0; i < heights.size(); ++i) {
        for (long long j = 0; j < heights[0].size(); ++j) {
            if (!visited[i][j] && heights[i][j] > targetHeight) {
                q.push({i, j});
                visited[i][j] = true;
                ++area;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto& dir : directions) {
                        long long nx = x + dir.first;
                        long long ny = y + dir.second;
                        if (nx >= 0 && nx < heights.size() && ny >= 0 && ny < heights[0].size() && !visited[nx][ny] && heights[nx][ny] > targetHeight) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                            ++area;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    long long h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<long long>> heights(h, vector<long long>(w));
    for (long long i = 0; i < h; ++i) {
        for (long long j = 0; j < w; ++j) {
            cin >> heights[i][j];
        }
    }

    for (long long year = 1; year <= y; ++year) {
        long long areaAboveSeaLevel = 0;
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        bfs(heights, visited, areaAboveSeaLevel, year);
        cout << areaAboveSeaLevel << endl;
    }

    return 0;
}