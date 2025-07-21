#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> unsafe;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        unsafe.insert({a, b});

        // All 8 possible moves
        long long moves[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

        for (auto &move : moves) {
            long long new_a = a + move[0];
            long long new_b = b + move[1];
            if (1 <= new_a && new_a <= N && 1 <= new_b && new_b <= N) {
                unsafe.insert({new_a, new_b});
            }
        }
    }

    cout << N * N - unsafe.size() << '\n';

    return 0;
}