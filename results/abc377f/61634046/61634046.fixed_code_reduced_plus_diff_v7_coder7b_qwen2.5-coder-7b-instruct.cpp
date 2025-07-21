#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 1e9;
const int MAX_M = 1e3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> rows(M + 1), cols(M + 1);
    vector<pair<int, int>> diagonals1(M + 1), diagonals2(M + 1);

    for (int i = 1; i <= M; ++i) {
        cin >> rows[i] >> cols[i];
        diagonals1[i] = {rows[i] + cols[i], i};
        diagonals2[i] = {rows[i] - cols[i], i};
    }

    sort(diagonals1.begin(), diagonals1.end());
    sort(diagonals2.begin(), diagonals2.end());

    set<int> occupied_rows, occupied_cols, occupied_diag1, occupied_diag2;

    for (int i = 1; i <= M; ++i) {
        occupied_rows.insert(rows[i]);
        occupied_cols.insert(cols[i]);
        occupied_diag1.insert(diagonals1[i].first);
        occupied_diag2.insert(diagonals2[i].first);
    }

    long long total_cells = static_cast<long long>(N) * N;
    long long valid_cells = total_cells;

    for (int i = 1; i <= M; ++i) {
        auto it1 = occupied_diag1.upper_bound(diagonals1[i].first);
        if (it1 != occupied_diag1.begin()) {
            --it1;
            int prev_diag1 = *it1;
            int diag_diff1 = diagonals1[i].first - prev_diag1;
            valid_cells -= diag_diff1 / 2;
        }

        auto it2 = occupied_diag2.upper_bound(diagonals2[i].first);
        if (it2 != occupied_diag2.begin()) {
            --it2;
            int prev_diag2 = *it2;
            int diag_diff2 = diagonals2[i].first - prev_diag2;
            valid_cells -= diag_diff2 / 2;
        }
    }

    cout << valid_cells << endl;

    return 0;
}