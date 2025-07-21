#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int dir[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    unordered_map<int, unordered_map<int, bool>> threat_map;
    for (auto& p : pieces) {
        for (auto& dir : dir) {
            int x = p.first + dir[0];
            int y = p.second + dir[1];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                threat_map[x][y] = true;
            }
        }
    }

    int safe_count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!threat_map[i][j]) {
                safe_count++;
            }
        }
    }

    cout << safe_count << endl;

    return 0;
}