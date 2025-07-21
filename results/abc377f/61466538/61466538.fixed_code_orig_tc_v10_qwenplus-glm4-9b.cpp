#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // To store the threatened squares
    vector<unordered_set<int>> threatened_rows(N + 1), threatened_cols(N + 1);
    vector<unordered_set<int>> threatened_d1(2 * N + 1), threatened_d2(2 * N + 1);

    // Mark the threatened squares for each piece
    for (auto &p : pieces) {
        int r = p.first, c = p.second;
        threatened_rows[r].insert(c);
        threatened_cols[c].insert(r);
        threatened_d1[r + c].insert(r);
        threatened_d2[r - c + N].insert(r);
    }

    // Calculate the number of threatened squares
    long long threatened_squares = 0;
    for (int i = 1; i <= N; ++i) {
        threatened_squares += threatened_rows[i].size();
        threatened_squares += threatened_cols[i].size();
        threatened_squares += threatened_d1[i].size();
        threatened_squares += threatened_d2[i].size();
    }

    // Total squares in the grid is N^2
    long long total_squares = N * N;
    long long safe_squares = total_squares - threatened_squares;

    cout << safe_squares << endl;

    return 0;
}