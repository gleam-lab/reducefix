#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> forbidden;
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        // Check all 8 possible knight moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }

    cout << N * N - forbidden.size() << '\n';

    return 0;
}