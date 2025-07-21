#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int dx[9] = {-2, -2, -1, -1, 1, 1, 2, 2, 0}; // x ç§»å¨
const int dy[9] = {-1, 1, -2, 2, -2, 2, -1, 1, 0}; // y ç§»å¨

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a - 1, b - 1}; // è½¬æ¢ä¸º 0-based index
    }

    vector<vector<bool>> occupied(N, vector<bool>(N, false));
    set<pair<int, int>> occupied_set;

    // æ è®°ææè¢«å æ®çä½ç½®
    for (auto& p : pieces) {
        occupied[p.first][p.second] = true;
        occupied_set.insert(p);

        for (int i = 0; i < 9; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                occupied[nx][ny] = true;
                occupied_set.insert({nx, ny});
            }
        }
    }

    // è®¡ç®æææªè¢«å æ®çä½ç½®æ°é
    long long free_positions = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!occupied[i][j]) {
                if (occupied_set.find({i, j}) == occupied_set.end()) {
                    free_positions++;
                }
            }
        }
    }

    cout << free_positions << endl;

    return 0;
}