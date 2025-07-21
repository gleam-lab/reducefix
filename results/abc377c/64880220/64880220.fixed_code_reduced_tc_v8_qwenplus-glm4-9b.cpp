#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point& p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

int main() {
    long long n, m;
    cin >> n >> m;

    vector<Point> points(m);
    set<Point> occupied;
    for (long long i = 0; i < m; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    // Define the capture patterns
    vector<vector<Point>> capturePatterns = {
        {{1, 0}}, {{-1, 0}}, {{0, 1}}, {{0, -1}}, // Vertical and horizontal
        {{2, 1}}, {{2, -1}}, {{-2, 1}}, {{-2, -1}} // Diagonal along the main diagonal
    };

    // Check each point and its capture patterns
    for (const auto& point : points) {
        for (const auto& pattern : capturePatterns) {
            Point newPoint = {point.x};
            for (const auto& dir : pattern) {
                newPoint.x += dir.x;
                newPoint.y += dir.y;
                if (newPoint.x >= 1 && newPoint.x <= n && newPoint.y >= 1 && newPoint.y <= n) {
                    occupied.insert(newPoint);
                }
            }
        }
    }

    // Count the number of free spaces
    long long freeSpaces = n * n;
    for (const auto& point : occupied) {
        freeSpaces--;
    }

    cout << freeSpaces << endl;
    return 0;
}