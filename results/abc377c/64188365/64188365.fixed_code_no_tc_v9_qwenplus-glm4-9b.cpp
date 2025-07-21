#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

struct Pos {
    int x, y;
};

int main() {
    long long n, m;
    cin >> n >> m;

    vector<Pos> pieces(m);
    set<pair<int, int>> captured;

    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].x >> pieces[i].y;
        --pieces[i].x;  // Convert 1-based index to 0-based
        --pieces[i].y;  // Convert 1-based index to 0-based
    }

    for (const auto& piece : pieces) {
        // Check all possible positions a piece can capture
        rep(dx, 3) {
            rep(dy, 3) {
                int nx = piece.x + dx;
                int ny = piece.y + dy;

                // Check if (nx, ny) is within bounds and not already captured
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (captured.find({nx, ny}) == captured.end()) {
                        captured.insert({nx, ny});
                    }
                }
            }
        }
    }

    // Calculate the number of empty cells that can be placed
    long long empty_cells = n * n;
    empty_cells -= captured.size();

    cout << empty_cells << endl;

    return 0;
}