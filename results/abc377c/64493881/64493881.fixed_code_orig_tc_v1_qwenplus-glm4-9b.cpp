#include <iostream>
#include <vector>
#include <set>

using namespace std;

// ä½¿ç¨ä½è¿ç®è¡¨ç¤ºæ£çç¶æ
const int MAXN = 1000000;
int board[MAXN];

// å¤æ­ä½ç½®æ¯å¦è¢«æ»å»
bool isAttacked(int x, int y) {
    // ...
}

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> pieces;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        pieces.insert({x, y});
    }

    int safeCount = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!isAttacked(i, j) && pieces.count({i, j}) == 0) {
                safeCount++;
            }
        }
    }

    cout << safeCount << endl;
    return 0;
}