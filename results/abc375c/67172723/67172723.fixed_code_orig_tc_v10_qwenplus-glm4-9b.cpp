#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    
    double total_cost = 0.0;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    
    // è®¡ç®ä»åç¹å°ç¬¬ä¸ä¸ªç¹åå°åç¹çè·ç¦»ï¼è¢«è®¡ç®äºä¸¤æ¬¡ï¼
    total_cost += 2 * hypot(points[0].first, points[0].second);
    
    // è®¡ç®ç¬¬ä¸ä¸ªç¹å°ç¬¬äºä¸ªç¹ï¼ç¬¬äºä¸ªç¹å°ç¬¬ä¸ä¸ªç¹ï¼...ï¼æåä¸ä¸ªç¹å°åç¹çè·ç¦»ï¼æ¯ä¸ªè·ç¦»è®¡ç®äºä¸æ¬¡ï¼
    for (int i = 0; i < n - 1; ++i) {
        total_cost += hypot(points[i + 1].first - points[i].first, points[i + 1].second - points[i].second);
    }
    
    cout.precision(10);
    cout << fixed << total_cost << endl;
    
    return 0;
}