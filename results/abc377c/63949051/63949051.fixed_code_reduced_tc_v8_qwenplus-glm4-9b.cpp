#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define the range of influence of a piece
const int RANGEX[8] = {2, 1, 1, 2, -2, -1, -1, -2};
const int RANGEDY[8] = {1, 2, 2, 1, 1, 2, 2, 1};

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Check if a position is safe from any piece
    auto is_safe = [&](int x, int y) -> bool {
        for (int i = 0; i < 8; i++) {
            if (x + RANGEX[i] <= 0 || x + RANGEX[i] > N || y + RANGEDY[i] <= 0 || y + RANGEDY[i] > N) {
                continue; // Out of bounds, skip this direction
            }
            for (int j = 0; j < M; j++) {
                if (pieces[j].first == x + RANGEX[i] && pieces[j].second == y + RANGEDY[i]) {
                    return false; // Captured
                }
            }
        }
        return true; // Safe
    };

    long long ans = 0;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            if (is_safe(x, y)) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}