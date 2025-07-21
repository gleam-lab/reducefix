#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10e9 + 10;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    vector<vector<bool>> captured(n + 1, vector<bool>(n + 1, false));

    // Function to mark captured positions
    auto mark_captured = [&](int a, int b) {
        // Implement capturing logic here
    };

    // Mark captured positions for each piece
    for (auto &piece : pieces) {
        mark_captured(piece.first, piece.second);
    }

    // Calculate the number of valid empty positions
    int valid_positions = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!captured[i][j]) {
                ++valid_positions;
            }
        }
    }

    cout << valid_positions << endl;

    return 0;
}