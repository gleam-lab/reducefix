#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;
    double total = 0.0;  // ä½¿ç¨ double ä»¥ä¾¿è¿è¡å¹³æ¹æ ¹è®¡ç®

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        // ä½¿ç¨ hypot æ¥è®¡ç®ä¸¤ç¹ä¹é´çè·ç¦»ï¼å®è¿åè·ç¦»çå¹³æ¹æ ¹
        total += hypot(curX - x, curY - y);

        curX = x;
        curY = y;
    }

    // è¿ååç¹
    total += hypot(curX, curY);

    // è®¾ç½®è¾åºç²¾åº¦ä»¥ç¬¦åè¦æ±
    cout << fixed << setprecision(9) << total << '\n';

    return 0;
}