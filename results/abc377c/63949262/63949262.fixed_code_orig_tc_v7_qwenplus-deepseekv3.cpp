#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> forbidden;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        // All possible knight moves
        long long dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        long long dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }

    long long total_squares = N * N;
    long long forbidden_count = forbidden.size();
    long long safe_squares = total_squares - forbidden_count;

    cout << safe_squares << '\n';

    return 0;
}