#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<int, int>> forbidden;
    set<pair<int, int>> pieces;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.emplace(a, b);
    }

    // Directions a knight can attack from
    const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (auto [a, b] : pieces) {
        for (int k = 0; k < 8; ++k) {
            int ni = a + dx[k];
            int nj = b + dy[k];
            if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
                forbidden.emplace(ni, nj);
            }
        }
    }

    // Total squares minus occupied squares minus forbidden squares
    // Need to count squares that are in forbidden but not occupied
    long long answer = N * N;
    answer -= M;
    
    for (auto [a, b] : forbidden) {
        if (!pieces.count({a, b})) {
            answer--;
        }
    }

    cout << answer << '\n';

    return 0;
}