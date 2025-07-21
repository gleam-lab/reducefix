#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> pieces;
    set<pair<long long, long long>> unsafe;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        unsafe.insert({a, b});

        const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long unsafe_count = unsafe.size();
    long long safe = total - unsafe_count;

    cout << safe << '\n';

    return 0;
}