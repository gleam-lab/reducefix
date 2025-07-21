#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> g(M);
    vector<i64> rows, cols, diag1, diag2, anti_diag1, anti_diag2;
    for (i64 i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        rows.push_back(a);
        cols.push_back(b);
        diag1.push_back(a + b);
        diag2.push_back(a - b);
        anti_diag1.push_back(a + b + 1);
        anti_diag2.push_back(a - b - 1);
    }

    // Sort and remove duplicates
    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());
    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());
    sort(anti_diag1.begin(), anti_diag1.end());
    sort(anti_diag2.begin(), anti_diag2.end());

    auto remove_duplicates = [](vector<i64>& v) {
        v.erase(unique(v.begin(), v.end()), v.end());
    };

    remove_duplicates(rows);
    remove_duplicates(cols);
    remove_duplicates(diag1);
    remove_duplicates(diag2);
    remove_duplicates(anti_diag1);
    remove_duplicates(anti_diag2);

    // Calculate the number of invalid positions
    i64 invalid_positions = 0;

    // Invalid due to rows and columns
    invalid_positions += rows.size() * N + cols.size() * N;

    // Invalid due to diagonals
    invalid_positions += diag1.size() * N + diag2.size() * N;

    // Invalid due to anti-diagonals
    invalid_positions += anti_diag1.size() * N + anti_diag2.size() * N;

    // Count intersections of diagonals and anti-diagonals
    auto count_intersections = [&](vector<i64>& v1, vector<i64>& v2) {
        i64 count = 0;
        i64 i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] == v2[j]) {
                count++;
                i++;
                j++;
            } else if (v1[i] < v2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return count;
    };

    i64 intersections_diag_antidiag = count_intersections(diag1, anti_diag1) + count_intersections(diag2, anti_diag2);
    invalid_positions -= intersections_diag_antidiag;

    // Calculate the number of valid positions
    i64 valid_positions = N * N - invalid_positions;

    cout << valid_positions << endl;

    return 0;
}