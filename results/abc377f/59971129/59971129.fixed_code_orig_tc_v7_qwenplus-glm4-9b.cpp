#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;

int N, M;
vector<pair<int, int>> pieces;

// Function to calculate the number of safe squares
long long countSafeSquares() {
    set<int> rows, cols, diag1, diag2;
    set<pair<int, int>> diag4, diag3;

    // Identify all captured lines
    for (auto &p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first - p.second);
        diag2.insert(p.first + p.second);
        diag3.insert({p.first - p.second, 2 * N - p.first - p.second});
        diag4.insert({2 * p.first - N, p.second});
    }

    // Calculate the number of safe squares
    long long total = N * N;
    int captured = 0;

    // Calculate the number of captured squares in rows
    for (int row : rows) {
        int left = max(1, row);
        int right = min(N, row);
        captured += right - left + 1;
    }

    // Calculate the number of captured squares in columns
    for (int col : cols) {
        int up = max(1, col);
        int down = min(N, col);
        captured += down - up + 1;
    }

    // Calculate the number of captured squares in diagonals
    for (int diag : diag1) {
        if (diag < 1 || diag >= 2 * N - 1) continue;
        int left = max(1, diag);
        int right = min(N, N - diag);
        captured += right - left + 1;
    }

    for (int diag : diag2) {
        if (diag < 1 || diag >= 2 * N - 1) continue;
        int up = max(1, diag);
        int down = min(N, N - diag);
        captured += down - up + 1;
    }

    for (auto &diag : diag3) {
        if (diag.first < 1 || diag.first >= 2 * N - 1 || diag.second < 1 || diag.second >= 2 * N - 1) continue;
        int left = max(1, diag.first);
        int right = min(N, N - diag.first);
        captured += right - left + 1;
    }

    for (auto &diag : diag4) {
        if (diag.first < 1 || diag.first >= 2 * N - 1 || diag.second < 1 || diag.second >= 2 * N - 1) continue;
        int up = max(1, diag.first);
        int down = min(N, N - diag.first);
        captured += down - up + 1;
    }

    return total - captured;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.push_back({a, b});
    }
    cout << countSafeSquares() << endl;
    return 0;
}