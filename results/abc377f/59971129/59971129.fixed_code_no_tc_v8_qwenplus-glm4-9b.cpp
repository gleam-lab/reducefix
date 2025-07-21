#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

#define N 1005
vector<int> rows, cols, diag1, diag2;

int main() {
    long long n, m;
    cin >> n >> m;
    rows.resize(n + 1);
    cols.resize(n + 1);
    diag1.resize(2 * n + 1);
    diag2.resize(2 * n + 1);

    while (m--) {
        int a, b;
        cin >> a >> b;
        rows[a]++;
        cols[b]++;
        diag1[a + b]++;
        diag2[a - b]++;
    }

    long long total_empty_squares = n * n;
    long long captured_squares = 0;

    // Count captured squares in rows and columns
    for (int i = 1; i <= n; ++i) {
        if (rows[i] > 1) captured_squares++;
        if (cols[i] > 1) captured_squares++;
    }

    // Count captured squares in diagonals
    for (int i = 1; i <= 2 * n; ++i) {
        if (diag1[i] > 1) captured_squares++;
        if (diag2[i] > 1) captured_squares++;
    }

    // Subtract captured squares from total
    cout << total_empty_squares - captured_squares << endl;

    return 0;
}