#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

const vector<pair<int, int>> knight_moves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

bool isValidMove(int N, int x, int y, set<pair<int, int>>& knight_positions) {
    for (const auto& move : knight_moves) {
        int nx = x + move.first;
        int ny = y + move.second;
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
            if (knight_positions.count({nx, ny})) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    set<pair<int, int>> knight_positions;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        knight_positions.insert({a, b});
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!knight_positions.count({i, j}) && isValidMove(N, i, j, knight_positions)) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}