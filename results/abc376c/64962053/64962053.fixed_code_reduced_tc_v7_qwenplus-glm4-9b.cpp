#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    for (int i = 0; i < n; ++i) cin >> va[i];
    for (int i = 0; i < n-1; ++i) cin >> vb[i];
    
    // å¯¹åçå­å¤§å°è¿è¡æåº
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    // æ¥æ¾å¯ä»¥ææçæå°çå­å¤§å°
    for (int i = 0; i < n-1; ++i) {
        // å¦æå½åçå­å¤§å°å°äºåä¸ä¸ªçå¤§å°ï¼åå¢å¤§çå­å¤§å°
        if (vb[i] < va[i]) {
            if (vb[i] < va[i-1]) {
                // å¦æå½åçå­å¤§å°å°äºåä¸ä¸ªçå­å¤§å°ï¼è¿å -1
                cout << -1 << endl;
                return 0;
            }
            // æ¾å°æ»¡è¶³æ¡ä»¶çæå°çå­å¤§å°
            cout << va[i] << endl;
            return 0;
        }
    }
    // å¦æææé½è½ç°æçå­ï¼è¿åæåä¸ä¸ªçå­å¤§å°
    cout << vb.back() << endl;
    return 0;
}