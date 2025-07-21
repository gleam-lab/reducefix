#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    vector<pair<long long, long long>> pieces(M);

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        attacked.insert(pieces[i]);
    }

    for (const auto& p : pieces) {
        long long x = p.first;
        long long y = p.second;

        // Generate all 8 possible attack positions
        vector<pair<long long, long long>> moves = {
            {x + 2, y + 1},
            {x + 1, y + 2},
            {x - 1, y + 2},
            {x - 2, y + 1},
            {x - 2, y - 1},
            {x - 1, y - 2},
            {x + 1, y - 2},
            {x + 2, y - 1}
        };

        for (const auto& move : moves) {
            if (move.first >= 1 && move.first <= N && move.second >= 1 && move.second <= N) {
                attacked.insert(move);
            }
        }
    }

    long long total_squares = N * N;
    long long unsafe_squares = attacked.size();
    long long safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << "\n";

    return 0;
}