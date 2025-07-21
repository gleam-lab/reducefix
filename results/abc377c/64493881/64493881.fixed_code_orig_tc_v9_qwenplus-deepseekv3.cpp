#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    set<pair<int, int>> existing_pieces;
    set<pair<int, int>> threatened;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});

        // Generate all 8 possible knight moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int x = a + dx[k];
            int y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                threatened.insert({x, y});
            }
        }
    }

    // The total safe positions are N*N minus the number of threatened positions minus the existing pieces, but existing pieces are already in threatened positions if they can be captured
    long long unsafe = 0;
    for (auto pos : threatened) {
        if (existing_pieces.find(pos) == existing_pieces.end()) {
            unsafe++;
        }
    }
    unsafe += existing_pieces.size(); // existing pieces make their positions unsafe for new placement

    long long safe = N * N - unsafe;
    cout << safe << '\n';

    return 0;
}