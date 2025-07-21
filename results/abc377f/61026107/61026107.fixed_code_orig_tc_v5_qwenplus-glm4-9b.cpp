#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<int> rows, cols, diag1, diag2;
    for (const auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first + p.second);
        diag2.insert(p.first - p.second);
    }

    // Calculate the number of empty squares
    ll totalEmptySquares = N * N;
    // Subtract squares in occupied rows and columns
    for (int r : rows) totalEmptySquares -= (N - rows.count(r));
    for (int c : cols) totalEmptySquares -= (N - cols.count(c));
    // Subtract squares in occupied diagonals
    for (int d : diag1) totalEmptySquares -= (N - diag1.count(d));
    for (int d : diag2) totalEmptySquares -= (N - diag2.count(d));
    // Subtract the intersections of occupied rows and columns
    for (int r : rows) {
        for (int c : cols) {
            totalEmptySquares -= diag1.count(r + c) + diag2.count(r - c);
        }
    }
    // Add back the over-counted squares at the intersections of rows, columns, and diagonals
    for (int r : rows) {
        for (int c : cols) {
            int d1 = r + c;
            int d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2)) {
                totalEmptySquares += 1;
            }
        }
    }

    cout << totalEmptySquares << endl;
    return 0;
}