#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    vector<pair<long long, long long>> pieces(M);

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        attacked.insert({a, b});
    }

    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (auto &p : pieces) {
        long long a = p.first;
        long long b = p.second;
        for (auto &move : moves) {
            long long x = a + move.first;
            long long y = b + move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    cout << N * N - attacked.size() << endl;

    return 0;
}