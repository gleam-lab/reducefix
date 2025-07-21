#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> pieces(M);
    set<long long> rows, cols, diag1, diag2, anti_diag1, anti_diag2;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        anti_diag1.insert(a - b);
        anti_diag2.insert(-a - b);
    }

    long long total_squares = N * N;
    long long captured_squares = 0;

    // Count the number of squares captured by rows
    for (long long row : rows) {
        captured_squares += N;
    }

    // Count the number of squares captured by columns
    for (long long col : cols) {
        captured_squares += N;
    }

    // Count the number of squares captured by diagonals
    for (long long diag : diag1) {
        long long min_pos = max(1LL, diag - N + 1);
        long long max_pos = min(diag, N);
        captured_squares += max_pos - min_pos + 1;
    }

    for (long long diag : diag2) {
        long long min_pos = max(1LL, -diag + 1);
        long long max_pos = min(N, diag);
        captured_squares += max_pos - min_pos + 1;
    }

    for (long long diag : anti_diag1) {
        long long min_pos = max(1LL, -diag - N + 1);
        long long max_pos = min(N, -diag);
        captured_squares += max_pos - min_pos + 1;
    }

    for (long long diag : anti_diag2) {
        long long min_pos = max(1LL, diag - N + 1);
        long long max_pos = min(N, diag);
        captured_squares += max_pos - min_pos + 1;
    }

    // Subtract the number of captured squares from the total number of squares
    long long valid_squares = total_squares - captured_squares;
    cout << valid_squares << endl;

    return 0;
}