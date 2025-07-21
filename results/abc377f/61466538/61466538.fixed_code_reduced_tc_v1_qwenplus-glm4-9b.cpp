#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Directions for rows, columns, and diagonals
    vector<pair<int, int>> dirs = {
        {0, 1}, {1, 0}, {1, 1}, {1, -1},
        {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}
    };

    set<pair<int, int>> blocked;

    // Mark blocked positions due to existing pieces
    for (const auto& p : pieces) {
        int x = p.first;
        int y = p.second;
        for (const auto& dir : dirs) {
            int i = x;
            int j = y;
            do {
                blocked.insert({i, j});
                i += dir.first;
                j += dir.second;
            } while (i > 0 && i <= N && j > 0 && j <= N);
        }
    }

    // Calculate the number of unblocked positions
    int unblockedCount = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (blocked.find({i, j}) == blocked.end()) {
                unblockedCount++;
            }
        }
    }

    cout << unblockedCount;
    return 0;
}