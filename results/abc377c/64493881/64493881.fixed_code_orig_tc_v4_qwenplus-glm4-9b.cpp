#include <iostream>
using namespace std;

const int N = 1001; // åè®¾ N <= 1000
const int D[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int main() {
    int N, M;
    cin >> N >> M;

    int blocked[N][N][8] = {0};
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; // è½¬æ¢ä¸º0-basedç´¢å¼
        for (int d = 0; d < 8; d++) {
            int nx = a + D[d][0], ny = b + D[d][1];
            if (1 <= nx && nx < N && 1 <= ny && ny < N) {
                blocked[nx][ny][d] = 1;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int free = 1;
            for (int d = 0; d < 8; d++) {
                int nx = i + D[d][0], ny = j + D[d][1];
                if (1 <= nx && nx < N && 1 <= ny && ny < N && blocked[nx][ny][d]) {
                    free = 0;
                    break;
                }
            }
            if (free) {
                result++;
            }
        }
    }

    cout << result << endl;
    return 0;
}