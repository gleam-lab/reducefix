#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<int, int>> all_cells;
    for (long long i = 1; i <= N * N; ++i) {
        all_cells.insert({i % N, i / N});
    }

    set<pair<int, int>> captured_cells;
    for (long long i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        vector<pair<int, int>> capture_moves = {
            {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
            {1, -2}, {2, -1}, {2, 1}, {1, 2}
        };

        for (auto move : capture_moves) {
            auto captured_row = max(0, min(N - 1, a + move.first));
            auto captured_col = max(0, min(N - 1, b + move.second));
            captured_cells.insert({captured_row, captured_col});
        }
    }

    long long captured_count = 0;
    for (auto cell : captured_cells) {
        if (all_cells.count(cell)) {
            captured_count++;
        }
    }

    cout << (N * N - captured_count) << endl;

    return 0;
}