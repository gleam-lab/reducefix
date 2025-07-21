#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> dangerous;
    vector<pair<long long, long long>> pieces(M);

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        dangerous.insert({a, b});
    }

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (auto& p : pieces) {
        long long a = p.first;
        long long b = p.second;
        for (int k = 0; k < 8; ++k) {
            long long nx = a + dx[k];
            long long ny = b + dy[k];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                dangerous.insert({nx, ny});
            }
        }
    }

    cout << N * N - dangerous.size() << '\n';

    return 0;
}