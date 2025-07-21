#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // Define the directions a piece can move to capture another piece
    vector<vector<int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Bitmask to store the positions of existing pieces
    bitset<1000000000> pieces;

    // Read the positions of existing pieces
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.set((a - 1) * N + (b - 1));
    }

    // Count the number of valid positions to place a new piece
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool valid = true;
            for (auto& dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni >= 0 && ni < N && nj >= 0 && nj < N && pieces.test(ni * N + nj)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}