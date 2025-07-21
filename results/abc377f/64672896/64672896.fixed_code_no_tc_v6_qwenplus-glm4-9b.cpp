#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    vector<array<i64, 2>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        cin >> pieces[i][0] >> pieces[i][1];
    }

    vector<i64> xs(pieces.size()), ys(pieces.size());

    // Collect all x and y coordinates from the pieces.
    for (i64 i = 0; i < M; ++i) {
        xs[i] = pieces[i][0];
        ys[i] = pieces[i][1];
    }

    // Sort to remove duplicates and make it easier to process.
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    // Calculate the total number of possible placements.
    i64 total = N * N;

    // Subtract the number of squares in each row and column that are capturable.
    for (i64 x : xs) {
        total -= min(N, x + 1);  // Subtract the whole row if it exists before the first piece
        total -= min(N, N - x);   // Subtract the whole row if it exists after the last piece
    }

    for (i64 y : ys) {
        total -= min(N, y + 1);  // Subtract the whole column if it exists before the first piece
        total -= min(N, N - y);   // Subtract the whole column if it exists after the last piece
    }

    // Subtract the squares where the pieces are placed.
    total -= M;

    // Output the result.
    cout << total << '\n';

    return 0;
}