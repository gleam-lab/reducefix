#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pieces(M);

    for (long long i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // éåæ£ççæ¯ä¸ªä½ç½®
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            bool is_safe = true;

            // æ£æ¥å½åæ£å­æ¯å¦å¨æ£å­å¯æè·
            for (const auto& p : pieces) {
                long long a = p.first;
                long long b = p.second;

                for (long long k = 0; k < 8; ++k) {
                    long long x = a + dx[k];
                    long long y = b + dy[k];

                    // æ£æ¥æ¯å¦è¶ç
                    if (x < 1 || x > N || y < 1 || y > N) continue;

                    // æ£æ¥æ¯å¦ææ£å­å¯ä»¥æè·å½åä½ç½®
                    if (find(pieces.begin(), pieces.end(), make_pair(x, y)) != pieces.end()) {
                        is_safe = false;
                        break;
                    }
                }

                if (!is_safe) break;
            }

            // å¦æå½åä½ç½®ï¼å¢å ä½ç½®è®¡æ°
            if (is_safe) safe_positions++;
        }
    }

    // è¾åºå¯è½çæ¾ç½®ä½ç½®æ°
    cout << safe_positions << endl;
}