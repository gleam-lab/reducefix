#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> x(M), y(M);
    for (int i = 0; i < M; ++i) {
        cin >> x[i] >> y[i];
        --x[i]; --y[i]; // è½¬æ¢ä¸ºä»0å¼å§çç´¢å¼
    }
    
    // éåæ¯ä¸ªæ£å­ï¼ç¡®å®å®å½±åçåºå
    for (int i = 0; i < M; ++i) {
        // åä¸æè·
        vector<pair<bool, int>> captures;
        int j = y[i], offset = 1;
        for (; j >= 0; --j, ++offset) {
            if (j < 0 || j >= N) break;
            captures.push_back({true, x[i] + offset});
            for (int k = 1; k < N; ++k) {
                if (x[i] + k < 0 || x[i] + k >= N) break;
                captures.push_back({false, x[i] + k});
            }
        }
        
        sort(captures.begin(), captures.end());
        vector<pair<int, bool>> impact(N * N);
        int idx = 0;
        for (auto& cap : captures) {
            int start = cap.second;
            int end = start;
            while (idx < (int)impact.size() && impact[idx].first < start) ++idx;
            while (idx < (int)impact.size() && impact[idx].first == start) {
                impact[idx] = {end, cap.second > impact[idx].second};
                ++idx;
                ++end;
            }
            impact[idx++] = {end, cap.second > impact[idx].second};
        }
        
        // æææ£å­åå®ä»¬å½±åçåºå
        vector<pair<int, pair<int, bool>>> pieces;
        for (int i = 0; i < N * N; ++i) {
            if (impact[i].first != impact[i + 1].first) {
                pieces.push_back({impact[i].first, {impact[i].second, impact[i].second == 0}});
            } else if (!impact[i].second) {
                pieces.push_back({impact[i].first, {impact[i].second, impact[i + 1].second}});
            }
        }
        
        sort(pieces.begin(), pieces.end());
        
        // éåæææ£å­ï¼åå¹¶å®ä»¬å½±åçåºå
        vector<pair<int, bool>> merged(N * N, {0, false});
        for (auto& piece : pieces) {
            int start = piece.first;
            int end = piece.first + N - 1;
            for (int i = 0; i < N; ++i) {
                bool occupied = false;
                for (int j = start; j <= end; ++j) {
                    if (merged[j].second) {
                        occupied = true;
                        break;
                    }
                }
                if (occupied) {
                    merged[start * N + i] = {end * N + i, true};
                } else {
                    merged[start * N + i] = {start * N + i, false};
                }
            }
        }
        
        // ç»è®¡å¯ç¨çç©ºä½
        int free_spaces = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!merged[i * N + j].second) {
                    ++free_spaces;
                }
            }
        }
        
        // è¾åºç»æ
        cout << free_spaces << endl;
    }
    
    return 0;
}