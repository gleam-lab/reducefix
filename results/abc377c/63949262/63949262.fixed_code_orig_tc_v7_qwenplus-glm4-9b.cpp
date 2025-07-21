#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    unordered_map<int, vector<int>> board;
    int x, y;
    
    // è¯»åæææ£å­çä½ç½®
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        board[x].push_back(y);
    }
    
    long long count = 0;
    
    // éåæ´ä¸ªæ£çï¼è®¡ç®å¯ç¨çç©ºæ ¼æ°é
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            // å¦æå½åæ ¼å­æ²¡æè¢«ä»»ä½æ£å­å ç¨ï¼åè®¡æ°
            if (find(board[i].begin(), board[i].end(), j) == board[i].end()) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}