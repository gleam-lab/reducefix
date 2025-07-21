#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);

    // è¯»åæ£å­ä½ç½®
    for (int i = 0; i < M; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // åå»ºä¸ä¸ªå¤§å°ä¸º N*N çäºç»´æ°ç»ï¼ç¨æ¥è¡¨ç¤ºæ£ç
    vector<vector<int>> board(N+1, vector<int>(N+1, 0));

    // ç¨æ£å­ä½ç½®åå§åæ£ç
    for (int i = 0; i < M; i++) {
        int x = pieces[i].first;
        int y = pieces[i].second;
        // æ£å­çæ»å»èå´
        board[x][y] = 1; // å½åæ£å­
        board[x+2][y+1] = 1; // å³ä¸è§
        board[x+1][y+2] = 1; // å³ä¸è§
        board[x-1][y+2] = 1; // å³ä¸è§
        board[x-2][y+1] = 1; // å³ä¸è§
        board[x-2][y-1] = 1; // å³ä¸è§
        board[x-1][y-2] = 1; // å³ä¸è§
        board[x+1][y-2] = 1; // å³ä¸è§
        board[x+2][y-1] = 1; // å³ä¸è§
    }

    // ç»è®¡æªå ç¨ç©ºä½çæ°é
    long long freeSpots = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == 0) {
                freeSpots++;
            }
        }
    }

    cout << freeSpots << endl;

    return 0;
}