#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 1); // ä½¿ç¨ N + 1 ä»¥æå¤§ N å¼
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;

    // éåæ¯ä¸ä¸ªæäºº
    for (int i = 0; i < N; i++) {
        // å½åæäººçå¥åº·å¼
        int health = H[i];

        // å½æäººå¥åº·å¤§äº0æ¶ï¼ç»§ç»­æ»å»
        while (health > 0) {
            if (T % 3 == 0) {
                // å¦æ T æ¯3çåæ°ï¼åæ¯æ¬¡åå°3
                health -= 3;
            } else {
                // å¦åæ¯æ¬¡åå°1
                health--;
            }
            // æ è®ºæ»å»å¤å°æ¬¡ï¼æ¶é´ T åªå¢å 1
            T++;
        }
    }
    
    // è¾åºæç»çæ¶é´ T
    cout << T << endl;
    return 0;
}