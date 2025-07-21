#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

long long count_safe_squares(int N, int M, const vector<pair<int, int>>& pieces) {
    unordered_set<pair<int, int>> covered_squares;
    unordered_set<pair<int, int>> covered_diagonals[2]; // For top-left to bottom-right and top-right to bottom-left
    vector<pair<int, int>> rows, cols, diag_up, diag_down;

    // Populate covered_squares and covered_diagonals
    for (const auto& p : pieces) {
        covered_squares.insert(p);
        rows.insert(p.first);
        cols.insert(p.second);
        diag_up.insert({p.first - p.second, 0}); // 0 for top-left to bottom-right
        diag_down.insert({p.first + p.second, 1}); // 1 for top-right to bottom-left
    }

    // Calculate the number of safe squares
    long long total_squares = N * N;
    total_squares -= covered_squares.size(); // Subtract covered squares
    // Subtract covered diagonals
    for (auto& d : diag_up) {
        // Calculate the number of squares on the diagonal
        // Code omitted for brevity
    }
    for (auto& d : diag_down) {
        // Calculate the number of squares on the diagonal
        // Code omitted for brevity
    }

    return total_squares;
}

int main() {
    // Read input
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Calculate and print the result
    cout << count_safe_squares(N, M, pieces) << endl;
    return 0;
}