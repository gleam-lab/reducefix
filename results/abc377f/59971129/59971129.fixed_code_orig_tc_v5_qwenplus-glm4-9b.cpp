#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

int main() {
    long long n, m;
    cin >> n >> m;
    vector<Point> points(m);
    for (int i = 0; i < m; ++i) {
        cin >> points[i].x >> points[i].y;
        --points[i].x; --points[i].y; // convert to 0-based index
    }

    set<Point> row_covered, col_covered, diag1_covered, diag2_covered;
    map<pair<int, int>, int> diagonal1, diagonal2;

    for (const auto& p : points) {
        row_covered.insert({p.x, INT_MAX});
        col_covered.insert({p.y, INT_MAX});
        diagonal1[{p.x + p.y, p.x - p.y}]++;
        diagonal2[{p.x + p.y, p.x - p.y}]++;
    }

    long long total_empty = n * n;
    long long covered = 0;

    // Rows and columns covered by a single piece
    covered += row_covered.size() + col_covered.size();
    for (const auto& p : row_covered) total_empty -= n - p.x;
    for (const auto& p : col_covered) total_empty -= n - p.y;

    // Diagonals covered by more than one piece
    for (const auto& p : diagonal1) {
        if (p.second > 1) covered++;
    }
    for (const auto& p : diagonal2) {
        if (p.second > 1) covered++;
    }

    // Adjust for over counting
    for (const auto& p : diagonal1) {
        if (p.second > 1) {
            for (int i = 0; i < p.second - 1; i++) {
                total_empty += n - (p.first.first - i + p.first.second - i);
            }
        }
    }
    for (const auto& p : diagonal2) {
        if (p.second > 1) {
            for (int i = 0; i < p.second - 1; i++) {
                total_empty += n - (p.first.first - i - p.first.second + i);
            }
        }
    }

    cout << total_empty - covered << endl;
    return 0;
}