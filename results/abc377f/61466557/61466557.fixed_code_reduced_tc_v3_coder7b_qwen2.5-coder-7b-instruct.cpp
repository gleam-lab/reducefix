#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

long long solve(long long n, long long m, const vector<pair<long long, long long>>& positions) {
    set<long long> rows, cols, diagonals1, diagonals2;

    for (const auto& pos : positions) {
        rows.insert(pos.first);
        cols.insert(pos.second);
        diagonals1.insert(pos.first - pos.second);
        diagonals2.insert(pos.first + pos.second);
    }

    long long total_empty_squares = n * n;
    long long occupied_by_rows = rows.size() * n;
    long long occupied_by_cols = cols.size() * n;
    long long occupied_by_diagonals = diagonals1.size() * n + diagonals2.size() * n;

    total_empty_squares -= occupied_by_rows + occupied_by_cols;
    total_empty_squares += rows.size() * cols.size();

    for (const auto& diagonal1 : diagonals1) {
        long long count_in_diagonal1 = min(n, 1LL * abs(diagonal1));
        total_empty_squares -= count_in_diagonal1;
        for (const auto& diagonal2 : diagonals2) {
            if ((diagonal1 + diagonal2) % 2 != 0) continue;
            long long common_count = min(count_in_diagonal1, min(1LL * abs(diagonal2), n));
            total_empty_squares += common_count;
        }
    }

    for (const auto& diagonal2 : diagonals2) {
        long long count_in_diagonal2 = min(n, 1LL * abs(diagonal2));
        total_empty_squares -= count_in_diagonal2;
        for (const auto& diagonal1 : diagonals1) {
            if ((diagonal1 + diagonal2) % 2 != 0) continue;
            long long common_count = min(count_in_diagonal1, min(1LL * abs(diagonal2), n));
            total_empty_squares += common_count;
        }
    }

    return total_empty_squares;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> positions(m);
    for (long long i = 0; i < m; ++i) {
        cin >> positions[i].first >> positions[i].second;
    }
    cout << solve(n, m, positions) << '\n';
    return 0;
}