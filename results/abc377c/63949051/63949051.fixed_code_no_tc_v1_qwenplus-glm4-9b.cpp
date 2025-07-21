#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1000 * 1000; // Maximum possible value for N

int n, m;
vector<pair<int, int>> pieces(MAX_N); // Stores the positions of the pieces

// Function to check if a square is within the grid boundaries
bool is_within_bounds(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

// Function to check if a square can be attacked by any of the existing pieces
bool is_attackable(int x, int y) {
    for (int i = 0; i < m; ++i) {
        int dx = pieces[i].first - x;
        int dy = pieces[i].second - y;
        if (abs(dx) == 2 && abs(dy) == 1) {
            return true; // Check the 8 possible attack patterns
        }
        if (abs(dx) == 1 && abs(dy) == 2) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    int count = 0; // Count of squares where the new piece can be placed
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            if (!is_attackable(x, y)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}