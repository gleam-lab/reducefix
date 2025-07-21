#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dx[8] = {2, 2, 2, -2, -2, -2, -1, 1};
const int dy[8] = {1, -1, -2, -2, 2, 2, 1, -1};

int main() {
    long long N, M;
    cin >> N >> M;
    
    vector<vector<int>> board(N, vector<int>(N, 0));
    while (M--) {
        long long a, b;
        cin >> a >> b;
        a--; b--; // è½¬æ¢ä¸º0-indexed
        board[a][b] = 1;
        for (int i = 0; i < 8; i++) {
            long long nx = a + dx[i];
            long long ny = b + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                board[nx][ny] = 1;
            }
        }
    }
    
    long long emptyCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                emptyCount++;
            }
        }
    }
    
    cout << emptyCount << endl;
    return 0;
}