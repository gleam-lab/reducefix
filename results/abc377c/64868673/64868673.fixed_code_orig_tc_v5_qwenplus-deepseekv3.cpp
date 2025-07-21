#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> existing_pieces;
    set<pair<long long, long long>> threatened;

    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});

        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (existing_pieces.find({x, y}) == existing_pieces.end()) {
                    threatened.insert({x, y});
                }
            }
        }
    }

    long long total_safe = N * N - existing_pieces.size() - threatened.size();
    cout << total_safe << endl;

    return 0;
}