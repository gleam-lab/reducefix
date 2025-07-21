#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const int dir[8][2] = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    vector<vector<bool>> can_place(N, vector<bool>(N, true));
    for (auto &p : pieces) {
        int x = p.first - 1;
        int y = p.second - 1;
        for (auto &dir : dir) {
            int nx = x + dir[0] * 2;
            int ny = y + dir[1] * 2;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                can_place[nx][ny] = false;
            }
        }
    }

    long long count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!can_place[i][j]) continue; // Skip occupied or inaccessible squares
            count++;
        }
    }

    cout << count << endl;
    return 0;
}