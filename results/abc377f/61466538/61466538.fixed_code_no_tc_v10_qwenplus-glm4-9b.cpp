#include <iostream>
using namespace std;

long long n, m;
vector<pair<int, int>> pieces;

long long solve() {
    long long total_empty_squares = n * n;
    long long used_squares = 0;

    // Track the number of pieces in each row, column, and diagonals
    vector<long long> rows(n + 1, 0), cols(n + 1, 0);
    vector<long long> diag1(2 * n + 1, 0), diag2(2 * n + 1, 0);

    for (auto& p : pieces) {
        int r = p.first, c = p.second;

        // Increment the count of pieces in the current row, column, and diagonals
        rows[r]++;
        cols[c]++;
        diag1[2 * r + c]++;
        diag2[2 * r - c]++;
    }

    // Calculate the number of used squares due to pieces in rows and columns
    for (int i = 1; i <= n; i++) {
        used_squares += rows[i] * (n - rows[i]); // Each row can't be paired with itself
        used_squares += cols[i] * (n - cols[i]); // Each column can't be paired with itself
    }

    // Calculate the number of used squares due to pieces on diagonals
    for (int i = 0; i < 2 * n; i++) {
        used_squares += diag1[i] * (diag1[i] - 1) / 2; // Combination of anti-diagonals
        used_squares += diag2[i] * (diag2[i] - 1) / 2; // Combination of diagonals
    }

    // Return the number of empty squares where you can place your piece
    return total_empty_squares - used_squares;
}

int main() {
    cin >> n >> m;
    pieces.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    cout << solve() << endl;
    return 0;
}