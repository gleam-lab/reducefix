#include <iostream>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<int, int>> rows, cols, diag1, diag2;

    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        rows.insert({x, 0});
        cols.insert({y, 0});
        diag1.insert({x + y, 0});
        diag2.insert({x - y, 0});
    }

    long long total_squares = N * N;

    // Calculate number of affected squares in rows and columns
    for (auto& r : rows) {
        r.second = (r.first == 1) ? N - 1 : N;
    }
    for (auto& c : cols) {
        c.second = (c.first == 1) ? N - 1 : N;
    }

    // Calculate number of affected squares in diagonals
    for (auto& d : diag1) {
        long long d_value = d.first;
        long long total_points = d_value + 1;
        if (d_value <= N + 1) {
            d.second = (d_value - 1 >= 1) ? total_points - 2 : 1;
        } else {
            d.second = (d_value - N >= 0) ? N - (d_value - N) : 0;
        }
    }
    for (auto& d : diag2) {
        long long d_value = d.first;
        long long total_points = d_value + 1;
        if (d_value >= -N) {
            d.second = (d_value + 1 <= N) ? total_points - 2 : 1;
        } else {
            d.second = (d_value + N <= 0) ? N - (-d_value - N) : 0;
        }
    }

    // Subtract affected squares from total squares
    for (auto& r : rows) {
        total_squares -= r.second;
    }
    for (auto& c : cols) {
        total_squares -= c.second;
    }
    for (auto& d : diag1) {
        total_squares -= d.second;
    }
    for (auto& d : diag2) {
        total_squares -= d.second;
    }

    cout << total_squares << endl;
    return 0;
}