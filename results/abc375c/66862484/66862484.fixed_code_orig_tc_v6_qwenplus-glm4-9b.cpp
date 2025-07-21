#include <iostream>
#include <cmath>  // For sqrt

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;   // ç¾å¨ä½ç½®ï¼åç¹ï¼
    long long total = 0;             // ç·ã³ã¹ã

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = curX - x;
        long long dy = curY - y;
        total += dx * dx + dy * dy;  // ç´¯ç©ããã®ã¯å¹³æ¹å¤

        curX = x; curY = y;
    }

    // æå¾ã®ç¹ããåç¹ã¸æ»ãè·é¢ãç´¯ç©ãã
    total += curX * curX + curY * curY;

    // çµæãåºåãã
    cout << sqrt(total) << '\n';

    return 0;
}