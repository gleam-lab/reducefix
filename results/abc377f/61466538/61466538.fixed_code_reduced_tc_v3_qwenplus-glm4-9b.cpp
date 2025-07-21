#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

// Function to calculate the number of captured squares by a line of pieces
ll capturedSquares(int start, int end, set<int>& pieces) {
    auto it = pieces.upper_bound(start);
    if (it != pieces.begin()) {
        --it;
    }
    int leftCapture = min(end, *it) - start + 1;
    it = pieces.lower_bound(end);
    int rightCapture = *it - max(it - pieces.begin() + 1, start) + 1;
    return leftCapture + rightCapture - 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<int> rows(n + 1), cols(n + 1), diag1(2 * n + 1), diag2(2 * n + 1);

    // Fill the sets with the positions of the pieces
    for (auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first + p.second);
        diag2.insert(p.first - p.second);
    }

    // Calculate the total number of captured squares
    ll captured = 0;
    captured += capturedSquares(1, n, rows);
    captured += capturedSquares(1, n, cols);
    captured += capturedSquares(1, 2 * n, diag1);
    captured += capturedSquares(1, 2 * n, diag2);

    // Calculate the number of safe squares
    ll safeSquares = n * n - captured;

    cout << safeSquares << endl;

    return 0;
}