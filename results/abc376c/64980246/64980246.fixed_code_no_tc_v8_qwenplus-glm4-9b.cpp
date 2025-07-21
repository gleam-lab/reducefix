#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    
    // Sortçå¤§å°ï¼ä»¥åçå­çå®¹é
    sort(a.begin(), a.end(), greater<int>()); // éåºæåå¤§å°
    sort(b.begin(), b.end()); // ååºæåçå­å¤§å°
    
    // åå§åæå°å¯è½å°ºå¯¸ä¸º 0
    int min_size = 0;
    // å¯¹äºæ¯ä¸ª
    for (int i = 0; i < n; ++i) {
        // å¦æå½åæ¯ææå·²ç¥ççå­é½å°ï¼åéè¦ä¸ä¸ªè³å°åè¯¥ä¸æ ·å¤§ççå­
        if (a[i] > min_size) {
            min_size = a[i];
        }
    }
    
    // è¾åºæå°å°ºå¯¸ççå­ï¼å¦æææé½å¯ä»¥å·²å­å¨ççå­ä¸­ï¼åæå°å°ºå¯¸ä¸º 0
    cout << min_size << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}