#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    
    // è¯»åæ£å­çä½ç½®
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a - 1, b - 1}; // è½¬æ¢ä¸º0ç´¢å¼
    }
    
    set<pair<int, int>> occupied;
    
    // è®°å½ææè¢«æ£å­å½±åçæ ¼å­
    for (auto& p : pieces) {
        int x = p.first, y = p.second;
        // è®¡ç®å½±åçæ ¼å­
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (dx == 0 && dy == 0) continue; // è·³è¿æ£å­æ¬èº«çæ ¼å­
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    occupied.insert({nx, ny});
                }
            }
        }
    }
    
    // è®¡ç®å¯ç¨çç©ºæ ¼å­æ°é
    long long total = N * N;
    long long used = occupied.size();
    cout << total - used << endl;
    
    return 0;
}