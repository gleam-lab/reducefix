#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    unordered_set<int> occupied_rows, occupied_cols, occupied_diag, occupied_anti_diag;

    for (long long i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        occupied_rows.insert(a);
        occupied_cols.insert(b);
        occupied_diag.insert(a + b);
        occupied_anti_diag.insert(a - b);
    }

    long long free_squares = N * N;

    // Subtract occupied rows and columns
    free_squares -= occupied_rows.size();
    free_squares -= occupied_cols.size();

    // Subtract occupied diagonals and anti-diagonals
    for (int i = 1; i <= N; ++i) {
        int diag = i + 1, anti_diag = i - 1;
        free_squares -= occupied_diag.count(diag) + occupied_anti_diag.count(anti_diag);
    }

    cout << free_squares << endl;

    return 0;
}