#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10e9 + 5;
const int MAXM = 2 * 10e5 + 10;
bool grid[MAXN][MAXN];

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        pieces[i] = {a, b};

        // Mark the capture area for each piece
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                int nx = a + dx;
                int ny = b + dy;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                grid[nx][ny] = true;
                nx = a + dx * 2;
                ny = b + dy;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                grid[nx][ny] = true;
                nx = a + dx;
                ny = b + dy * 2;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                grid[nx][ny] = true;
                nx = a + dx * 2;
                ny = b + dy * 2;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                grid[nx][ny] = true;
            }
        }
    }

    // Count the number of squares not in the capture area
    long long count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!grid[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}