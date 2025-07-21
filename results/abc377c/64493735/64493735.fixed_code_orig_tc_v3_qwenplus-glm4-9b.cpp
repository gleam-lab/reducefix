#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    // ä¸å¯ç¨æ ¼å­çæ°é
    long long invalid_count = 0;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        // è®¡ç®å½åæ£å­å¯ä»¥æ»å»çç©ºç½æ ¼æ°é
        // æ³¨æï¼ç±äºæ£çæ¯å¯¹ç§°çï¼æä»¬å¯ä»¥åªè®¡ç®æ£å­ä¸ä¾§çæ»å»èå´ï¼ç¶åä¹ä»¥2
        invalid_count += min(2, b) + min(2, N - b) + min(2, a) + min(2, N - a);
        // ç±äºLå½¢ç¶çå¯¹ç§°æ§ï¼æ¯ä¸ªè§è½çæ ¼å­è¢«è®¡ç®äº4æ¬¡ï¼æ¯ä¸ªè¾¹çæ ¼å­è¢«è®¡ç®äº2æ¬¡
        // å æ­¤ï¼æä»¬éè¦åå»å¤è®¡ç®çè§è½æ ¼å­æ°éåè¾¹æ ¼å­æ°é
        invalid_count -= 4 * min(min(2, a), min(2, N - a)) - 2 * min(min(2, b), min(2, N - b));
    }

    // æ£çæ»æ ¼å­æ°
    long long total_squares = N * N;
    // å¯ç¨æ ¼å­çæ°é
    long long valid_squares = total_squares - invalid_count;

    cout << valid_squares << endl;

    return 0;
}