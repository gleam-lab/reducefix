#include <iostream>
#include <set>
#include <vector>

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
        
        // Check all 8 possible positions where this piece can capture
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1},
            {a + 1, b + 2},
            {a - 1, b + 2},
            {a - 2, b + 1},
            {a - 2, b - 1},
            {a - 1, b - 2},
            {a + 1, b - 2},
            {a + 2, b - 1}
        };

        for (const auto& move : moves) {
            if (move.first >= 1 && move.first <= N && move.second >= 1 && move.second <= N) {
                unsafe_squares.insert(move);
            }
        }
    }

    long long total_squares = N * N;
    long long unsafe_count = unsafe_squares.size();
    long long safe_count = total_squares - unsafe_count;

    cout << safe_count << endl;

    return 0;
}