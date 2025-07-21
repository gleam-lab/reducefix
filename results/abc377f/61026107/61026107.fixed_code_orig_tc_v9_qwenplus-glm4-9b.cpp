#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

using ll = long long;

struct Point {
    int x, y;

    bool operator < (const Point& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

int count_empty_squares(int n, const vector<Point>& occupied) {
    unordered_map<int, vector<int>> occupied_in_rows, occupied_in_cols;
    unordered_map<int, vector<int>> occupied_in_diag1, occupied_in_diag2;

    for (const auto& point : occupied) {
        occupied_in_rows[point.x].push_back(point.y);
        occupied_in_cols[point.y].push_back(point.x);
        occupied_in_diag1[point.x + point.y].push_back(point.y);
        occupied_in_diag2[point.x - point.y].push_back(point.y);
    }

    int total_empty = n * n;

    // Subtract occupied rows, columns, and diagonals
    for (auto& row : occupied_in_rows) {
        total_empty -= (row.second.size() + 1);
    }
    for (auto& col : occupied_in_cols) {
        total_empty -= (col.second.size() + 1);
    }
    for (auto& diag1 : occupied_in_diag1) {
        total_empty -= (diag1.second.size() + 1);
    }
    for (auto& diag2 : occupied_in_diag2) {
        total_empty -= (diag2.second.size() + 1);
    }

    return total_empty;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Point> occupied(m);
    for (int i = 0; i < m; ++i) {
        cin >> occupied[i].x >> occupied[i].y;
    }

    cout << count_empty_squares(n, occupied) << '\n';

    return 0;
}