#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // To store the number of pieces in every possible configuration of step sizes
    vector<int> cnt(4 * N + 1, 0);
    
    // Mark the cells that can be captured by each piece
    for (auto& piece : pieces) {
        int x = piece.first, y = piece.second;
        cnt[2 * (x - 1) + (y - 1) + 1]++; // x+2, y+1
        cnt[2 * (x - 1) + (y - 1) + 2]++; // x+1, y+2
        cnt[2 * (x - 1) + (y - 1) + 3]++; // x-1, y+2
        cnt[2 * (x - 1) + (y - 1) + 4]++; // x-2, y+1
        cnt[2 * (x - 1) + (y - 1) + 5]++; // x-2, y-1
        cnt[2 * (x - 1) + (y - 1) + 6]++; // x-1, y-2
        cnt[2 * (x - 1) + (y - 1) + 7]++; // x+1, y-2
        cnt[2 * (x - 1) + (y - 1) + 8]++; // x+2, y-1
    }

    // Calculate the number of safe cells
    long long ans = 0;
    for (int i = 1; i <= 4 * N; ++i) {
        int c = cnt[i];
        if (c > 0) {
            int x = (i - 1) / 2 + 1;
            int y = (i - 1) % 2 == 0 ? (x + 1) / 2 : (x + 2) / 2;
            if (x <= N && y <= N) {
                ans += (long long)x * y - c;
            } else {
                ans += (long long)x * y;
            }
        } else {
            int x = (i - 1) / 2 + 1;
            int y = (i - 1) % 2 == 0 ? (x + 1) / 2 : (x + 2) / 2;
            ans += (long long)x * y;
        }
    }

    cout << ans << endl;

    return 0;
}