#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

const vector<pair<int, int>> knight_moves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

bool isValid(int x, int y, int n) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int piece_num;
    cin >> piece_num;

    unordered_set<string> attacked_positions;

    for (int k = 0; k < piece_num; ++k) {
        int x, y;
        cin >> x >> y;

        for (const auto& move : knight_moves) {
            int nx = x + move.first;
            int ny = y + move.second;

            if (isValid(nx, ny, N)) {
                attacked_positions.insert(to_string(nx) + "," + to_string(ny));
            }
        }
    }

    int valid_positions = N * N - attacked_positions.size();
    cout << valid_positions << endl;

    return 0;
}