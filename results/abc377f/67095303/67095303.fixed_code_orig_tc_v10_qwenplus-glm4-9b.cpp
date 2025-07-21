#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {
    long long n, m;
    cin >> n >> m;

    // Use sets to track captured rows and columns
    set<long long> captured_rows, captured_cols;
    vector<pair<long long, long long>> diagonals;
    
    for (long long i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        captured_rows.insert(x);
        captured_cols.insert(y);
        diagonals.emplace_back(x + y, x - y);
    }

    // Calculate the number of captured squares
    long long captured_squares = 0;
    captured_squares += captured_rows.size() * n;
    captured_squares += captured_cols.size() * n;
    for (auto& diag : diagonals) {
        if (diag.first <= 2 * n && diag.first >= -2 * n) {
            captured_squares += min(n - abs(diag.first), n - abs(diag.second));
        }
    }

    // Calculate the total number of squares and the safe squares
    long long total_squares = n * n;
    long long safe_squares = total_squares - captured_squares;

    // Output the result modulo MOD
    cout << safe_squares % MOD << endl;

    return 0;
}