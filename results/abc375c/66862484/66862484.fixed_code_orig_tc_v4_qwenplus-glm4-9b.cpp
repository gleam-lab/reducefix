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

    vector<pair<long long, long long>> points;
    long long curX = 0, curY = 0; // åç¹åæ 
    long long total = 0; // æ»è·ç¦»

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    for (int i = 0; i < N; ++i) {
        long long x2, y2;
        tie(x2, y2) = points[i];
        long long dx = abs(curX - x2);
        long long dy = abs(curY - y2);
        total += dx * dx + dy * dy; // ç´¯å è·ç¦»
        curX = x2;
        curY = y2;
    }

    // æåçç¹ä»åç¹è¿åï¼ä¸éè¦åæ·»å è·ç¦»

    // è®¾ç½®å°æ°ç¹ç²¾åº¦ï¼å¹¶è¾åºè·ç¦»
    cout << fixed << setprecision(10) << sqrt(total) << endl;
    
    return 0;
}