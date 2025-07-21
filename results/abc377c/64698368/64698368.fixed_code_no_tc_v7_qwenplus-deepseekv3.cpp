#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    set<pair<int, int>> unsafe;
    set<pair<int, int>> pieces;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        pieces.insert({a, b});
        for (auto [dx, dy] : directions) {
            int nx = a + dx;
            int ny = b + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                unsafe.insert({nx, ny});
            }
        }
    }

    ll total = (ll)N * N;
    ll unsafe_count = unsafe.size();
    ll occupied = M;
    ll answer = total - occupied - unsafe_count;

    // Now, we need to subtract any positions that are both in pieces and unsafe
    // But since pieces are already not in the unsafe set (unless they can be captured by another piece)
    // So we need to count the number of pieces that are in unsafe positions
    ll overlap = 0;
    for (auto [a, b] : pieces) {
        if (unsafe.count({a, b})) {
            overlap++;
        }
    }

    answer += overlap; // Because these were subtracted twice (once in occupied, once in unsafe)

    cout << answer << endl;

    return 0;
}