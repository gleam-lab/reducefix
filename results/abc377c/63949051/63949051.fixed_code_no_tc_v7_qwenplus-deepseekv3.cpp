#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> pieces;
    unordered_set<long long> attacked;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        attacked.insert((a - 1) * N + b); // Mark the piece's position as attacked

        // Check all 8 possible attack positions
        const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            long long ni = a + dx[k];
            long long nj = b + dy[k];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                attacked.insert((ni - 1) * N + nj);
            }
        }
    }

    long long total = N * N - attacked.size();
    cout << total << endl;

    return 0;
}