#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

const int MAXN = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    long long M;
    cin >> N >> M;

    set<pair<long long, long long>> threatening_positions;

    // Directions a knight can move
    vector<pair<long long, long long>> directions = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    // Mark all positions that a knight can attack from (i, j)
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            for (auto& dir : directions) {
                long long ni = i + dir.first;
                long long nj = j + dir.second;
                if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                    threatening_positions.insert({ni, nj});
                }
            }
        }
    }

    // Calculate the number of empty squares
    long long total_empty_squares = N * N;
    total_empty_squares -= threatening_positions.size();

    cout << total_empty_squares << endl;

    return 0;
}