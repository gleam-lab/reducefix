#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> forbidden;
    set<pair<long long, long long>> existing_pieces;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});
        forbidden.insert({a, b});

        // All possible positions that can be captured by (a, b)
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto &move : moves) {
            long long x = move.first;
            long long y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long forbidden_count = forbidden.size();
    long long answer = total - forbidden_count;

    cout << answer << endl;

    return 0;
}