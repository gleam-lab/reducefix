#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_max = 1e9;
bool can_capture[N_max][N_max];

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        --pieces[i].first;  // Convert to 0-indexed
        --pieces[i].second; // Convert to 0-indexed
    }

    for (int i = 0; i < M; ++i) {
        int x = pieces[i].first;
        int y = pieces[i].second;
        can_capture[x][y] = true; // The piece itself can't capture

        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    can_capture[nx][ny] = true;
                }
            }
        }
    }

    int free_squares = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!can_capture[i][j]) {
                ++free_squares;
            }
        }
    }

    cout << free_squares << endl;

    return 0;
}