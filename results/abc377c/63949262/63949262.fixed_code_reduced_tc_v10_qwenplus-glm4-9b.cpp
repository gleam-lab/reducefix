#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> can_capture(N + 1, vector<bool>(N + 1, false));
    
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        // Mark the diamond pattern of capture for each piece
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    can_capture[nx][ny] = true;
                }
            }
        }
    }
    
    // Calculate the number of cells that are not captured
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!can_capture[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}