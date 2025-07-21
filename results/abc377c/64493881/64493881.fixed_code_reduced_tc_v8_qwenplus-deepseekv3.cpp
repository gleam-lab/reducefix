#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> forbidden;
    vector<pair<long long, long long>> existing(M);

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing[i] = {a, b};
        forbidden.insert({a, b});
    }

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (auto [a, b] : existing) {
        for (int k = 0; k < 8; ++k) {
            long long ni = a + dx[k];
            long long nj = b + dy[k];
            if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
                forbidden.insert({ni, nj});
            }
        }
    }

    cout << N * N - forbidden.size() << '\n';

    return 0;
}