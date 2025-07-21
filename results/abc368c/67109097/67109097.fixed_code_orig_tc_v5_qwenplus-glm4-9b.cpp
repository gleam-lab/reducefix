#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;

    // éåæ¯ä¸ªæäººçå¥åº·å¼
    for (int health : H) {
        // è®¡ç®è½å¤è¢«3æ´é¤çé¨ååæ æ³æ´é¤çé¨å
        T += health / 3 * 3;
        health %= 3;

        // å¦æææ æ³æ´é¤çä½æ°ï¼æä»¬éè¦é¢å¤çæ»å»æ¥åå°å¥åº·å¼
        if (health == 2) {
            T += 3;  // å ä¸ºæ¯æ¬¡æ»å»åå°3ï¼æä»¬å¯ä»¥å°ä½æ°2åä¸º0
        }
    }

    cout << T << endl;
    return 0;
}