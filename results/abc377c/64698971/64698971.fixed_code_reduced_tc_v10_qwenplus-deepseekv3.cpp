#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> forbidden;

    // The 8 possible moves a knight can make
    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        for (auto move : moves) {
            long long new_a = a + move.first;
            long long new_b = b + move.second;

            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                forbidden.insert({new_a, new_b});
            }
        }
    }

    long long total_squares = N * N;
    long long forbidden_count = forbidden.size();
    long long safe_squares = total_squares - forbidden_count - M; // Subtract M because the existing pieces' positions are not safe

    cout << safe_squares << endl;

    return 0;
}