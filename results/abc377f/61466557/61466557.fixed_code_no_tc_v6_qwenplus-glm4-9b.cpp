#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long n, m;

// Check if a point is within the bounds of the grid
bool inBounds(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

// Calculate the number of points that can be captured by a piece placed at (i, j)
int calculateCaptures(int i, int j, const vector<pair<int, int>>& pieces) {
    set<pair<int, int>> captures;

    // Capture by row
    for (int x : pieces) {
        if (x.first == i) {
            captures.insert({x.first, x.second});
        }
    }
    // Capture by column
    for (int x : pieces) {
        if (x.second == j) {
            captures.insert({x.first, x.second});
        }
    }
    // Capture by diagonal (i + j)
    for (int x : pieces) {
        if (x.first + x.second == i + j) {
            captures.insert({x.first, x.second});
        }
    }
    // Capture by anti-diagonal (i - j)
    for (int x : pieces) {
        if (x.first - x.second == i - j) {
            captures.insert({x.first, x.second});
        }
    }

    return captures.size();
}

int main() {
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    long long answer = n * n; // Total number of squares

    // Subtract squares that are captured by existing pieces
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (calculateCaptures(i, j, pieces) == 0) {
                answer--;
            }
        }
    }

    cout << answer << endl;
    return 0;
}