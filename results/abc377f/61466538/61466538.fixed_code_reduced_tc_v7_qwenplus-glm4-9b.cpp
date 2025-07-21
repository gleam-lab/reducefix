#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Define a point in the grid
using Point = pair<int, int>;

// Helper function to add to the answer
void add_to_answer(int &ans, int value) {
    ans += value;
    if (ans < 0) ans = 0;
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<Point> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Directions for capture lines
    const vector<Point> directions = {
        {1, 0},  // Rows
        {0, 1},  // Columns
        {1, 1},  // Diagonal (top-left to bottom-right)
        {1, -1}  // Anti-diagonal (top-right to bottom-left)
    };

    // Set to store all points that can be captured
    set<Point> captured_points;

    // For each piece, calculate points that can be captured
    for (const auto &piece : pieces) {
        for (const auto &dir : directions) {
            int x = piece.first, y = piece.second;
            while (x <= n && y <= n) {
                captured_points.insert({x, y});
                x += dir.first;
                y += dir.second;
            }
            x = piece.first, y = piece.second;
            while (x >= 1 && y >= 1) {
                captured_points.insert({x, y});
                x -= dir.first;
                y -= dir.second;
            }
        }
    }

    // Calculate the number of safe squares
    long long answer = n * n;  // Total squares
    for (const auto &point : captured_points) {
        // Subtract points that are on the same row or column
        answer -= 1LL * (point.first == 1 || point.first == n ||
                          point.second == 1 || point.second == n);
    }

    // Output the result
    cout << answer << endl;

    return 0;
}