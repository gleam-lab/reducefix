#include <iostream>
#include <vector>
#include <set>

using namespace std;

const vector<pair<int, int>> capture_directions = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool is_safe(int i, int j, const set<pair<int, int>>& occupied_cells) {
    for (auto dir : capture_directions) {
        int x = i + dir.first;
        int y = j + dir.second;
        if (x >= 0 && x < N && y >= 0 && y < N && occupied_cells.find({x, y}) != occupied_cells.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    set<pair<int, int>> occupied_cells;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied_cells.insert({a - 1, b - 1});
    }

    int count_safe_cells = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (occupied_cells.find({i, j}) == occupied_cells.end() && is_safe(i, j, occupied_cells)) {
                ++count_safe_cells;
            }
        }
    }

    cout << count_safe_cells << endl;
}