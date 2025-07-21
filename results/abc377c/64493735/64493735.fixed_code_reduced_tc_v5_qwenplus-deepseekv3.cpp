#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> unsafe;
    vector<pair<long long, long long>> existing;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing.emplace_back(a, b);
        unsafe.insert({a, b});
    }

    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (const auto& piece : existing) {
        long long a = piece.first;
        long long b = piece.second;
        for (const auto& move : moves) {
            long long new_a = a + move.first;
            long long new_b = b + move.second;
            if (1 <= new_a && new_a <= N && 1 <= new_b && new_b <= N) {
                unsafe.insert({new_a, new_b});
            }
        }
    }

    cout << N * N - unsafe.size() << '\n';

    return 0;
}