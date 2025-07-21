#include <iostream>
#include <vector>
#include <set>
using namespace std;

using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;

    set<int> rows, cols, diag1, diag2;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        rows.insert(pieces[i].first);
        cols.insert(pieces[i].second);
        diag1.insert(pieces[i].first + pieces[i].second);
        diag2.insert(pieces[i].first - pieces[i].second);
    }

    int free_squares = N * N; // Start with total squares

    // Subtract squares captured by rows
    for (int row : rows) {
        if (row >= 1 && row <= N) {
            free_squares -= (N - 1); // All squares in this row are captured
        }
    }

    // Subtract squares captured by columns
    for (int col : cols) {
        if (col >= 1 && col <= N) {
            free_squares -= (N - 1); // All squares in this column are captured
        }
    }

    // Subtract squares captured by diagonals
    for (int d : diag1) {
        int min_val = max(1, d - N + 1);
        int max_val = min(N, d);
        free_squares -= (max_val - min_val + 1);
    }
    for (int d : diag2) {
        int min_val = max(1, 1 - d);
        int max_val = min(N, N + d - 1);
        free_squares -= (max_val - min_val + 1);
    }

    cout << free_squares << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}