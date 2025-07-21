#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> pieces(M);
    for (long long i = 0; i < M; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<long long> rows, cols, diag1, diag2;

    // Populate sets with piece positions
    for (const auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first + p.second - 1); // i + j - 1
        diag2.insert(p.first - p.second + 1); // i - j + 1
    }

    // Calculate the number of positions that are not on any of the lines of capture
    long long ans = N * N;

    // Subtract the positions on the rows
    ans -= (N - rows.size());

    // Subtract the positions on the columns
    ans -= (N - cols.size());

    // Subtract the positions on the diagonals
    for (long long d : diag1) {
        if (d < 1 || d > 2 * N - 2) continue; // Diagonal must be within bounds
        set<long long> occupied;
        for (const auto& p : pieces) {
            if (p.first + p.second - 1 == d) {
                occupied.insert(p.first);
            }
        }
        ans -= (N - occupied.size());
    }

    for (long long d : diag2) {
        if (d < 0 || d > N + N - 2) continue; // Diagonal must be within bounds
        set<long long> occupied;
        for (const auto& p : pieces) {
            if (p.first - p.second + 1 == d) {
                occupied.insert(p.first);
            }
        }
        ans -= (N - occupied.size());
    }

    cout << ans << endl;

    return 0;
}