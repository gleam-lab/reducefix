#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<pair<int, int>> P;

int main() {
    cin >> N >> M;
    P.resize(M);
    for (auto &p : P) cin >> p.first >> p.second;

    set<int> rows, cols, diag1, diag2;
    set<pair<int, int>, greater<pair<int, int>>> diag1_set, diag2_set;

    // Collect captured rows, columns, diagonals, and anti-diagonals
    for (auto &p : P) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first + p.second);
        diag2.insert(p.first - p.second);
    }

    // Calculate captured squares
    int captured = 0;
    captured += rows.size() * N; // Captured by rows
    captured += cols.size() * N; // Captured by columns
    captured += diag1.size();    // Captured by diagonals i+j
    captured += diag2.size();    // Captured by diagonals i-j

    // Subtract overlaps
    // Overlaps between rows and columns
    captured -= rows.size() * cols.size();

    // Overlaps between diagonals and anti-diagonals
    for (auto &d1 : diag1) {
        auto it = diag2.lower_bound({-d1.first, 0});
        if (it != diag2.end() && it->first == d1.first) {
            captured -= 2; // Overlap at (d1.first, -d1.first)
        }
    }

    // Total squares minus captured squares
    cout << N * N - captured << endl;

    return 0;
}