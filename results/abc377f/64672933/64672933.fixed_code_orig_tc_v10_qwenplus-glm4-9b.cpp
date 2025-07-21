#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

long long count_empty_squares(int N, int M, vector<pair<int, int>>& pieces) {
    // Get the unique rows, columns, diagonals (sum) and anti-diagonals (difference)
    unordered_set<int> unique_rows, unique_cols, unique_diag1, unique_diag2;
    for (auto& piece : pieces) {
        unique_rows.insert(piece.first);
        unique_cols.insert(piece.second);
        unique_diag1.insert(piece.first + piece.second);
        unique_diag2.insert(piece.first - piece.second);
    }

    // Calculate the number of non-overlapping rows, columns, diagonals, and anti-diagonals
    int non_overlapping_rows = unique_rows.size();
    int non_overlapping_cols = unique_cols.size();
    int non_overlapping_diag1 = unique_diag1.size();
    int non_overlapping_diag2 = unique_diag2.size();

    // Calculate the total number of squares that can be captured
    long long total_captured = 0;
    total_captured += (N - non_overlapping_rows) * N; // Rows not in the unique set
    total_captured += N * (N - non_overlapping_cols); // Columns not in the unique set
    total_captured += (N - non_overlapping_diag1) * (N - non_overlapping_diag2); // Diagonals not in the unique set

    return (N * N - total_captured);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    cout << count_empty_squares(N, M, pieces) << endl;

    return 0;
}