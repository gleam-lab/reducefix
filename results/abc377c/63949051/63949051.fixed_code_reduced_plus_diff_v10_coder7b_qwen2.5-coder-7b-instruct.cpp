#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isSafe(int N, int x, int y, const unordered_set<long long>& knightPositions) {
    // Directions for a knight move
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int k = 0; k < 8; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && knightPositions.count(((long long)(nx - 1)) * N + (ny - 1))) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long M;
    cin >> M;

    unordered_set<long long> knightPositions;
    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        knightPositions.insert(((long long)(x - 1)) * N + (y - 1));
    }

    long long safeCount = 0;
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            if (!knightPositions.count(((long long)(i - 1)) * N + (j - 1)) && isSafe(N, i, j, knightPositions)) {
                ++safeCount;
            }
        }
    }

    cout << safeCount << endl;

    return 0;
}