#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> pieces(m);
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Sets to keep track of affected rows, columns, and diagonals
    set<long long> affected_rows, affected_cols, affected_d1, affected_d2;

    // Mark the affected rows, columns, and diagonals
    for (const auto& piece : pieces) {
        long long a = piece.first, b = piece.second;
        affected_rows.insert(a);
        affected_cols.insert(b);
        affected_d1.insert(a + b);
        affected_d2.insert(a - b);
    }

    // Calculate the number of good positions
    long long total_empty = n * n - m;
    long long bad_positions = 0;

    // Subtract the bad positions from the total empty positions
    for (long long i = 1; i <= n; ++i) {
        if (affected_rows.count(i) > 0) {
            bad_positions += 1; // Entire row is bad
        }
        if (affected_cols.count(i) > 0) {
            bad_positions += 1; // Entire column is bad
        }
        if (affected_d1.count(i) > 0) {
            bad_positions += 1; // Entire diagonal i+j is bad
        }
        if (affected_d2.count(i) > 0) {
            bad_positions += 1; // Entire diagonal i-j is bad
        }
    }

    cout << total_empty - bad_positions << endl;

    return 0;
}