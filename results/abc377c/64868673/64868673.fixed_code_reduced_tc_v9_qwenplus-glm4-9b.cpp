#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> pieces(m);
    
    // Input all pieces
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Directions that a piece can move to capture other pieces
    vector<pair<int, int>> directions = {
        {1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, -2}
    };

    // Check if a given position is safe for placing a new piece
    auto is_safe = [&](long long x, long long y) {
        for (auto &dir : directions) {
            long long nx = x + dir.first * 2, ny = y + dir.second * 2;
            if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
                for (auto &piece : pieces) {
                    if (piece.first == nx && piece.second == ny) {
                        return false;
                    }
                }
            }
        }
        return true;
    };

    long long ans = 0;
    // Count all safe positions
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (is_safe(i, j)) {
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}