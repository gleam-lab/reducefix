#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<int, int>> pieces;
    set<pair<int, int>> attacked;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // Check all 8 possible attack positions
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; k++) {
            int nx = a + dx[k];
            int ny = b + dy[k];
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                attacked.insert({nx, ny});
            }
        }
    }

    // Total squares - squares with pieces - squares under attack (not counting those with pieces)
    long long total = N * N;
    long long pieces_count = pieces.size();
    long long attacked_count = attacked.size();

    // Count how many attacked squares don't have pieces
    for (auto &p : pieces) {
        if (attacked.count(p)) {
            attacked_count--;
        }
    }

    long long safe_squares = total - pieces_count - attacked_count;
    cout << safe_squares << '\n';

    return 0;
}