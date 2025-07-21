#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<int, int>> occupied;
    set<pair<int, int>> threatened;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // All possible knight moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int x = a + dx[k];
            int y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (occupied.find({x, y}) == occupied.end()) {
                    threatened.insert({x, y});
                }
            }
        }
    }

    long long total_squares = N * N;
    long long occupied_count = occupied.size();
    long long threatened_count = threatened.size();
    long long safe_squares = total_squares - occupied_count - threatened_count;

    cout << safe_squares << endl;

    return 0;
}