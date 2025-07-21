#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool can_place(vector<vector<bool>>& can_capture, int x, int y) {
    return x >= 0 && x < can_capture.size() && y >= 0 && y < can_capture[0].size() && !can_capture[x][y];
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> can_capture(N, vector<bool>(N, false));

    set<pair<int, int>> pieces;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.insert({a - 1, b - 1});
        
        // æ è®°ææè½è¢«å½åæ£å­æè·çæ ¼å­
        for (int j = 0; j < 8; ++j) {
            int nx = a - 1 + dx[j];
            int ny = b - 1 + dy[j];
            if (can_place(can_capture, nx, ny)) {
                can_capture[nx][ny] = true;
            }
        }
    }

    int count = 0;
    // è®¡ç®æªè¢«ä»»ä½æ£å­æè·çç©ºæ ¼å­æ°é
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!can_capture[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}