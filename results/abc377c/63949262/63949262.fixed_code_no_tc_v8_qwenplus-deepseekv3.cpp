#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> unsafe_squares;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        unsafe_squares.insert({a, b});

        // Check all 8 possible knight moves
        const long long dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const long long dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (long long j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe_squares.insert({x, y});
            }
        }
    }

    long long total_squares = N * N;
    long long unsafe_count = unsafe_squares.size();
    long long safe_count = total_squares - unsafe_count;

    cout << safe_count << '\n';

    return 0;
}