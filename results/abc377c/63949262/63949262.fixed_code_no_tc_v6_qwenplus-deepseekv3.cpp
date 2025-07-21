#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied_and_attackable;
    set<pair<long long, long long>> occupied;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        occupied_and_attackable.insert({a, b});

        // Check all 8 possible attack positions
        const long long dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const long long dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                occupied_and_attackable.insert({x, y});
            }
        }
    }

    long long total_squares = N * N;
    long long invalid_squares = occupied_and_attackable.size();
    long long answer = total_squares - invalid_squares;

    cout << answer << endl;

    return 0;
}