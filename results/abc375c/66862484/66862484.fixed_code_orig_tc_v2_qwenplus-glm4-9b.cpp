#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;   // ç¾å¨ä½ç½®ï¼åç¹ï¼
    long long total = 0;           // ç·ã³ã¹ã

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        // è¨ç®è·é¢ã®å¹³æ¹
        total += (curX - x) * (curX - x) + (curY - y) * (curY - y);
        curX = x; curY = y;
    }

    // æå¾ã®ç¹ããåç¹ã¸æ»ã
    total += (curX - 0) * (curX - 0) + (curY - 0) * (curY - 0);

    // æ»è·ç¦»å¼å¹³æ¹å¾å°æç»è·ç¦»
    long long distance = sqrt(total);

    // è¾åºæç»è·ç¦»
    cout << distance << endl;

    return 0;
}