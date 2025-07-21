#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1000000000

int N, M;
vector<pair<int, int>> pieces(MAXN);

vector<vector<bool>> blocked(MAXN + 1, vector<bool>(MAXN + 1, false));

void mark_blocked(int x, int y) {
    // Check in all directions and mark the reachable cells as blocked
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            if (i == 0 && j == 0) continue; // Skip the current cell
            int nx = x + i, ny = y + j;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                blocked[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        mark_blocked(pieces[i].first, pieces[i].second);
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!blocked[i][j]) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}