#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define lld long long
#define pii pair<int, int>

int main() {
    int n, m;
    cin >> n >> m;

    // Maps to count occurrences of rows, columns, and diagonals
    vector<set<int>> captured(2, set<int>(n + 1));
    set<int> rows, cols, diags1, diags2;

    // Read the positions of the existing pieces and mark the capturing ranges
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);

        // Mark diagonals
        diags1.insert(x - y);
        diags2.insert(x + y);
    }

    // Calculate the number of captured cells
    int capturedCells = rows.size() * n + cols.size() * n;

    // Subtract the cells that are captured by diagonals
    for (int diag : diags1) {
        int minBound = max(1, diag - n + 1);
        int diagSize = min(minBound, n) - max(diag, 1);
        capturedCells -= diagSize;
    }

    for (int diag : diags2) {
        int minBound = max(1, -diag - n + 1);
        int diagSize = min(minBound, n) - max(diag, 1);
        capturedCells -= diagSize;
    }

    // Calculate the number of unoccupied cells
    lld totalCells = n * n;
    lld unoccupiedCells = totalCells - capturedCells;

    // Subtract the cells that lie on the borders and corners
    unoccupiedCells -= (n + 1) * 4;  // All border cells
    unoccupiedCells -= 4 * (n * n - 4 * n + 4);  // All corner cells

    cout << unoccupiedCells << endl;

    return 0;
}