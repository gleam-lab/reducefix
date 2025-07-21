#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<int, int>> attacked;
    set<pair<int, int>> pieces;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.emplace(a, b);

        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int ni = a + dx[k];
            int nj = b + dy[k];
            if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
                attacked.emplace(ni, nj);
            }
        }
    }

    long long total_squares = N * N;
    long long attacked_count = attacked.size();
    long long pieces_count = pieces.size();

    // Squares that are either attacked or occupied
    set<pair<int, int>> combined;
    for (auto p : attacked) combined.insert(p);
    for (auto p : pieces) combined.insert(p);
    long long unsafe_count = combined.size();

    long long safe_squares = total_squares - unsafe_count;
    cout << safe_squares << '\n';

    return 0;
}