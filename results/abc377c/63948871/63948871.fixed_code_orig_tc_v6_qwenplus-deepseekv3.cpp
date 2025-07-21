#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> pieces;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        attacked.insert({a, b});

        // All 8 possible knight moves
        const long long dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const long long dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (long long j = 0; j < 8; ++j) {
            long long ni = a + dx[j];
            long long nj = b + dy[j];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                attacked.insert({ni, nj});
            }
        }
    }

    long long total_squares = N * N;
    long long unsafe_squares = attacked.size();
    long long safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << endl;

    return 0;
}