#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long count_safe_squares(int N, vector<pair<int, int>>& pieces) {
    long long total_squares = 1LL * N * N;
    int rows = N, cols = N, diag1 = N, diag2 = N;

    for (auto& p : pieces) {
        int x = p.first, y = p.second;
        rows = min(rows, x);
        cols = min(cols, y);
        diag1 = min(diag1, x + y);
        diag2 = min(diag2, abs(x - y));
    }

    // Calculate total affected squares
    long long affected_squares = (rows * N) + (cols * N) + (diag1 * N) + (diag2 * N);
    // Subtract squares counted twice
    affected_squares -= (rows + cols + diag1 + diag2);

    return total_squares - affected_squares;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    cout << count_safe_squares(N, pieces) << endl;
    return 0;
}