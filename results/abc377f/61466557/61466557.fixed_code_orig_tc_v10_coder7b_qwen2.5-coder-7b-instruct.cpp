#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool inBounds(int i, int j, int n) {
    return 1 <= i && i <= n && 1 <= j && j <= n;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
    }

    set<int> row, col, d1, d2;
    for (const auto &[i, j] : q) {
        row.insert(i);
        col.insert(j);
        d1.insert(i - j);
        d2.insert(i + j);
    }

    int totalCapturable = 0;

    // Rows and Columns
    totalCapturable += (int)row.size() * (n - (int)row.size());
    totalCapturable += (int)col.size() * (n - (int)col.size());

    // Diagonals
    for (int d : d1) {
        int count = 0;
        for (int r : row) {
            int c = r - d;
            if (inBounds(r, c, n)) count++;
        }
        totalCapturable += count;
    }

    for (int d : d2) {
        int count = 0;
        for (int r : row) {
            int c = d - r;
            if (inBounds(r, c, n)) count++;
        }
        totalCapturable += count;
    }

    // Adjust for overcounting diagonals
    for (int d : d1) {
        int count = 0;
        for (int c : col) {
            int r = d + c;
            if (inBounds(r, c, n)) count++;
        }
        totalCapturable -= count;
    }

    for (int d : d2) {
        int count = 0;
        for (int c : col) {
            int r = d - c;
            if (inBounds(r, c, n)) count++;
        }
        totalCapturable -= count;
    }

    // Calculate valid squares
    int validSquares = n * n - totalCapturable;
    cout << validSquares << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}