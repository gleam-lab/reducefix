#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];

    // Pair toys and initial box sizes with their original indices
    vector<pair<int, int>> toys(a.begin(), a.end());
    vector<pair<int, int>> boxes(b.begin(), b.end());
    
    // Sortåçå­å¤§å°
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    // æ£æ¥è½å¦åå§ççå­ä¸­
    for (int i = 0; i < n; ++i) {
        if (boxes[i].first < toys[i].first) {
            // å¦æä¸è½åå§çå­ï¼æ¥æ¾æå°ççå­å¤§å°x
            int j = lower_bound(boxes.begin(), boxes.end(), make_pair(toys[i].first, INT_MAX)) - boxes.begin();
            if (j == n - 1) {
                // å¦ææ²¡æè¶³å¤ççå­å®¹éï¼è¾åº-1
                cout << -1 << endl;
                return 0;
            }
            // è¾åºæå°å®¹éx
            cout << boxes[j].first << endl;
            return 0;
        }
    }

    // å¦æææé½è½åå§çå­ï¼è¾åºä¸ä¸ä¸ªå¯è½ççå­å¤§å°
    cout << toys[0].first << endl;
}