#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> pieces;

// æ£æ¥ä½ç½® (i, j) æ¯å¦å¨æ£ç
bool is_valid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

// æ è®°ä½ç½® (i, j) ä¸ºä¸è½æ¾ç½®æ°çæ£å­
void mark_invalid(int i, int j) {
    if (is_valid(i, j)) {
        can_place[i][j] = false;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        pieces.emplace_back(x, y);
        //é¤ææä¸ (x, y)çå¯ä»¥æ¾ç½®æ£å­çä½ç½®
        mark_invalid(x, y);
        mark_invalid(x + 1, y);
        mark_invalid(x + 2, y + 1);
        mark_invalid(x + 2, y);
        mark_invalid(x - 1, y + 2);
        mark_invalid(x, y + 2);
        mark_invalid(x - 2, y + 2);
        mark_invalid(x - 2, y - 1);
        mark_invalid(x, y - 2);
        mark_invalid(x - 1, y);
        mark_invalid(x + 1, y - 2);
        mark_invalid(x, y - 2);
        mark_invalid(x + 2, y - 1);
    }

    int valid_count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (can_place[i][j]) {
                ++valid_count;
            }
        }
    }

    cout << valid_count << endl;

    return 0;
}