#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n, m;

struct Point {
    int x, y;
};

long long calculateEmptyPositions(int row, int col, const vector<Point>& occupied) {
    long long total = n * n;
    int count = 0;

    // Count covered positions by existing pieces
    for (const auto& p : occupied) {
        if (p.x == row || p.y == col) {
            count++;
        } else if (abs(p.x - p.y) == abs(row - col)) {
            count++;
        } else if (abs(p.x + p.y) == abs(row + col)) {
            count++;
        }
    }

    return total - count;
}

int main() {
    cin >> n >> m;
    vector<Point> occupied(m);
    for (int i = 0; i < m; i++) {
        cin >> occupied[i].x >> occupied[i].y;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += calculateEmptyPositions(i, j, occupied);
        }
    }

    cout << ans << endl;
    return 0;
}