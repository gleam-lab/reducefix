#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

long long n, m;

struct Point {
    int x, y;
};

long long countEmptySpaces(int n, const vector<Point>& pieces) {
    unordered_set<long long> row, col, diag1, diag2;
    long long total = 0;
    for (const auto& p : pieces) {
        total -= (row.count(p.x) ? 0 : (n - 1)) + (col.count(p.y) ? 0 : (n - 1));
        row.insert(p.x);
        col.insert(p.y);
        diag1.insert(p.x + p.y - 2);  // Convert 1-based to 0-based index
        diag2.insert(p.x - p.y + n - 1);  // Convert 1-based to 0-based index
    }

    // Calculate the number of empty spaces in diagonals
    for (const auto& d : diag1) {
        long long low = max(d - n + 1, 0LL);  // Negative index handling
        long long high = min(d, n - 1);
        total += high - low + 1;
    }

    for (const auto& d : diag2) {
        long long low = max(d - n + 1, 0LL);
        long long high = min(d, n - 1);
        total += high - low + 1;
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    vector<Point> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].x >> pieces[i].y;
    }

    cout << n * n - countEmptySpaces(n, pieces);
    return 0;
}