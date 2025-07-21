#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_set<long long> attacked;
const long long HASH_BASE = 1000000007;

void mark_attacked(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N) {
        long long hash = (long long)x * HASH_BASE + y;
        attacked.insert(hash);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    vector<pair<int, int>> moves = {
        {0, 0},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        // Convert to 0-based index
        a--; b--;

        for (auto [dx, dy] : moves) {
            int nx = a + dx;
            int ny = b + dy;
            mark_attacked(nx, ny);
        }
    }

    // Total squares minus the number of attacked squares
    cout << (1LL * N * N - (long long)attacked.size()) << endl;

    return 0;
}