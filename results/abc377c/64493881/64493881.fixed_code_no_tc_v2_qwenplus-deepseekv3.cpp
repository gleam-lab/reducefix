#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<int, int>> existing;
    set<pair<int, int>> unsafe;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        existing.insert({a, b});

        // All possible capture positions
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int x = a + dx[k];
            int y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }

    // Total positions: N*N
    // Existing pieces: M
    // Unsafe positions: unsafe.size()
    // But some unsafe positions might already be in existing pieces
    // So total unsafe = unsafe.size() + M - overlap
    // To avoid double-counting, we can subtract positions that are in both existing and unsafe
    long long unsafe_count = unsafe.size();
    for (const auto& p : existing) {
        if (unsafe.count(p)) {
            unsafe_count--;
        }
    }

    long long total_safe = N * N - M - unsafe_count;
    cout << total_safe << endl;

    return 0;
}