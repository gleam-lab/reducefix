#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> pieces(m);
    unordered_set<long long> rows, cols, diag1, diag2;

    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares in the grid
    long long total_squares = n * n;

    // Subtract squares in captured rows and columns
    long long captured_by_rows = rows.size() - 1LL; // subtract the row where all pieces are
    long long captured_by_cols = cols.size() - 1LL; // subtract the column where all pieces are
    long long captured_by_diag1 = diag1.size();
    long long captured_by_diag2 = diag2.size();

    // Calculate the number of squares that can be placed
    long long valid_squares = total_squares -
                             captured_by_rows -
                             captured_by_cols -
                             captured_by_diag1 -
                             captured_by_diag2;

    cout << valid_squares << endl;

    return 0;
}