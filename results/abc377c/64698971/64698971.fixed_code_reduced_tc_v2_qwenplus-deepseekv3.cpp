#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> threatened;
    set<pair<long long, long long>> existing_pieces;

    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        existing_pieces.insert({a, b});
        for (const auto& move : moves) {
            long long new_a = a + move.first;
            long long new_b = b + move.second;
            if (new_a >= 0 && new_a < N && new_b >= 0 && new_b < N) {
                threatened.insert({new_a, new_b});
            }
        }
    }

    long long total_squares = N * N;
    long long safe_squares = total_squares - threatened.size() - existing_pieces.size();

    cout << safe_squares << endl;
    return 0;
}