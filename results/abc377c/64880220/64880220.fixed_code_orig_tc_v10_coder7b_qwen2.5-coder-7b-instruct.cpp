#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int N) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> pieces;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    long long count = 0;
    vector<vector<bool>> visited(N + 2, vector<bool>(N + 2, false));

    // Directions for capturing pieces
    vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (const auto& piece : pieces) {
        long long x = piece.first, y = piece.second;

        // Check all directions to see if the piece can be captured
        bool canBeCaptured = false;
        for (int d = 0; d < 8; ++d) {
            long long nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny, N) && pieces.find({nx, ny}) != pieces.end()) {
                canBeCaptured = true;
                break;
            }
        }

        // If the piece can't be captured, count its neighbors as valid positions
        if (!canBeCaptured) {
            for (int d = 0; d < 8; ++d) {
                long long nx = x + dx[d], ny = y + dy[d];
                if (isValid(nx, ny, N)) {
                    count++;
                }
            }
        }
    }

    // Subtract the number of pieces themselves from the count
    count -= M;

    cout << count << endl;

    return 0;
}