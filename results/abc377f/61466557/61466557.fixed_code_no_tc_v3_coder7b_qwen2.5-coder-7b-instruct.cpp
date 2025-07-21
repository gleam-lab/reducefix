#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// Function to check if a position is within the bounds of the grid
bool inBounds(long long x, long long y, long long n) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

// Main function to solve the problem
void solve() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> positions(m);
    for(long long i = 0; i < m; ++i) {
        cin >> positions[i].first >> positions[i].second;
    }

    // Sets to store occupied rows, columns, diagonals
    set<long long> rows, cols, diag1, diag2;

    // Populate the sets with occupied positions
    for(const auto &pos : positions) {
        rows.insert(pos.first);
        cols.insert(pos.second);
        diag1.insert(pos.first - pos.second);
        diag2.insert(pos.first + pos.second);
    }

    // Calculate the total number of empty squares
    long long totalEmptySquares = n * n;

    // Subtract the number of squares occupied by rows and columns
    totalEmptySquares -= rows.size() * n + cols.size() * n;

    // Add back the intersections since they were subtracted twice
    totalEmptySquares += rows.size() * cols.size();

    // Iterate over each diagonal and adjust the count accordingly
    for(const auto &diag : diag1) {
        long long cnt = max(0LL, min(diag, n - diag));
        totalEmptySquares -= cnt;
    }
    for(const auto &diag : diag2) {
        long long cnt = max(0LL, min(diag, n - diag));
        totalEmptySquares -= cnt;
    }

    // Output the result
    cout << totalEmptySquares << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // Uncomment the line below to read multiple test cases
    // cin >> t;
    while(t--) solve();
    return 0;
}