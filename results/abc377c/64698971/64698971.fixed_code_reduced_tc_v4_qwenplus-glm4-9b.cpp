#include <iostream>
#include <set>
using namespace std;

// Directions a piece can move to capture other pieces
const int dx[] = {-1, -1, -1, 1, 1, 1, 1, 1};
const int dy[] = {-2, -2, 2, 2, -2, 2, -2, 2};

int main() {
    int N, M;
    cin >> N >> M;
    set<pair<int, int>> occupied;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        occupied.insert({x - 1, y - 1}); // Store 0-indexed positions
    }

    long long count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Check if the current cell is not occupied
            if (occupied.find({i, j}) == occupied.end()) {
                // Check if the current cell can be attacked by any occupied cell
                bool can_attack = false;
                for (int dir = 0; dir < 8; ++dir) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N && occupied.find({nx, ny}) != occupied.end()) {
                        can_attack = true;
                        break;
                    }
                }
                if (!can_attack) {
                    // If not attacked by any occupied cell, it's a valid spot
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}