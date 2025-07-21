#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_place[1000][1000];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        // Mark cells that cannot be placed on
        for (int x = max(0, a - 2), y = max(0, b - 2); x <= min(N - 1, a + 2) && y <= min(N - 1, b + 2); ++x, ++y) {
            can_place[x][y] = false;
        }
    }

    long long empty_cells = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (can_place[i][j]) {
                empty_cells++;
            }
        }
    }

    cout << empty_cells << endl;
    return 0;
}