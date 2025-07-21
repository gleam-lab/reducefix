#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> pieces(M);
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Sort pieces by each unique combination of their row and column
    vector<pair<long long, long long>> rows(M);
    for (long long i = 0; i < M; ++i) {
        rows[i] = {pieces[i].first, pieces[i].second};
    }
    sort(rows.begin(), rows.end());

    vector<pair<long long, long long>> cols(M);
    for (long long i = 0; i < M; ++i) {
        cols[i] = {pieces[i].second, pieces[i].first};
    }
    sort(cols.begin(), cols.end());

    // Calculate the number of capturing rows and columns
    long long capturing_rows = 1;
    long long capturing_cols = 1;
    for (long long i = 1; i < M; ++i) {
        if (rows[i].first == rows[i - 1].first) {
            capturing_rows++;
        }
        if (cols[i].first == cols[i - 1].first) {
            capturing_cols++;
        }
    }

    // The total number of squares is N^2
    // The number of squares that can be captured is the sum of capturing rows and columns
    // since each row or column overlapping the first captured one is also captured
    long long total_squares = N * N;
    long long captured_squares = capturing_rows + capturing_cols;

    // Subtract the captured squares from the total squares to get the number of safe squares
    cout << total_squares - captured_squares << endl;

    return 0;
}