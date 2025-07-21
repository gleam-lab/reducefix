#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> capture_area;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < 8; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                capture_area.insert({nx, ny});
            }
        }
    }

    long long total_squares = N * N;
    long long captured_squares = capture_area.size();

    cout << total_squares - captured_squares << endl;

    return 0;
}