#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> pieces;

int main() {
    cin >> N >> M;
    pieces.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<int> rows, cols, diag1, diag2, antidiag1, antidiag2;

    // Collect unique positions affected by each piece
    for (const auto &p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first + p.second);
        diag2.insert(p.first - p.second);
        antidiag1.insert(-p.first + p.second);
        antidiag2.insert(-p.first - p.second);
    }

    // Count the number of affected squares
    int count = rows.size() + cols.size() + diag1.size() + diag2.size() + antidiag1.size() + antidiag2.size();

    // Subtract the number of overlapping affected squares
    for (const auto &d : diag1) {
        int x = min(d, N - d - 1);
        for (int i = 0; i <= x; ++i) {
            rows.erase(i + 1);
            cols.erase(d - i);
        }
    }
    for (const auto &d : diag2) {
        int x = min(d, N - d - 1);
        for (int i = 0; i <= x; ++i) {
            rows.erase(i + 1);
            cols.erase(d + i);
        }
    }
    for (const auto &d : antidiag2) {
        int x = min(d, N - d - 1);
        for (int i = 0; i <= x; ++i) {
            rows.erase(i + 1);
            cols.erase(N - d - i);
        }
    }
    for (const auto &d : antidiag1) {
        int x = min(d, N - d - 1);
        for (int i = 0; i <= x; ++i) {
            rows.erase(i + 1);
            cols.erase(N - d + i);
        }
    }

    int ans = N * N - count + rows.size() + cols.size();
    cout << ans << endl;

    return 0;
}