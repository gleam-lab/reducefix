#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pieces(M);
    set<long long> row ThreatenedRows, col ThreatenedCols, diag1 ThreatenedDiag1, diag2 ThreatenedDiag2;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        ThreatenedRows.insert(a);
        ThreatenedCols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    long long safeSquares = N * N;
    // Subtract squares in threatened rows, columns, diagonals
    safeSquares -= ThreatenedRows.size() * N;
    safeSquares -= ThreatenedCols.size() * N;
    safeSquares -= ThreatenedDiag1.size();
    safeSquares -= ThreatenedDiag2.size();

    // Remove overlaps of threatened squares
    for (auto& p : pieces) {
        // Threatened on the same row or column
        safeSquares -= (ThreatenedRows.count(p.first) || ThreatenedCols.count(p.second)) ? 1 : 0;
        // Threatened on diagonals
        safeSquares -= (diag1.count(p.first + p.second) || diag2.count(p.first - p.second)) ? 1 : 0;
    }

    cout << safeSquares << endl;
    return 0;
}