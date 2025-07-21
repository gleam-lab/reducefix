#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<int, int>> occupied;
    for (long long i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.emplace(a, b);
    }

    long long emptySquares = N * N;
    set<pair<int, int>> occupiedRows, occupiedCols, occupiedDiags1, occupiedDiags2;

    for (const auto& p : occupied) {
        occupiedRows.insert(p.first);
        occupiedCols.insert(p.second);

        // Diagonal 1: i + j = constant
        occupiedDiags1.insert({p.first + p.second, 0});
        // Diagonal 2: i - j = constant
        occupiedDiags2.insert({p.first - p.second, 0});
    }

    // Subtract occupied rows and columns
    emptySquares -= occupiedRows.size() * N;
    emptySquares -= occupiedCols.size() * N;

    // Subtract occupied diagonals
    // For diagonal 1: i + j = constant, subtract all occupied values
    // For diagonal 2: i - j = constant, subtract all occupied values
    for (const auto& diag : occupiedDiags1) {
        int diagKey = diag.first;
        auto it = occupiedDiags1.lower_bound(diag);
        while (it != occupiedDiags1.end() && it->first == diagKey) {
            emptySquares -= (it->second - diag.second);
            ++it;
        }
    }
    for (const auto& diag : occupiedDiags2) {
        int diagKey = diag.first;
        auto it = occupiedDiags2.lower_bound(diag);
        while (it != occupiedDiags2.end() && it->first == diagKey) {
            emptySquares -= (it->second - diag.second);
            ++it;
        }
    }

    cout << emptySquares << endl;
    return 0;
}