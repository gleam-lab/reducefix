#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    vector<int> a(n);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());
    
    // å½ååéäºº
    int leading_votes = a[0];
    int leading_candidate = 1;
    int extra_votes = 0;
    int candidates_elected = 1;
    
    // åé¢å¤çéç¥¨
    for (int i = 1; i < n; i++) {
        if (leading_votes == a[i]) {
            candidates_elected++;
        } else if (candidates_elected < m) {
            extra_votes += m - candidates_elected;
            candidates_elected = m;
        }
        leading_votes = a[i];
        leading_candidate = i + 1;
    }
    
    // å¯¹äºæ¯ä¸ªåéäººï¼è®¡ç®ä»ä»¬éè¦è·å¾çæå°é¢å¤éç¥¨æ°
    for (int i = 0; i < n; i++) {
        int required_votes = leading_votes - a[i];
        if (i < leading_candidate - 1 || (i >= leading_candidate && extra_votes >= required_votes)) {
            cout << 0 << " ";
        } else if (extra_votes + (n - i - 1) >= required_votes) {
            required_votes -= extra_votes;
            extra_votes -= required_votes;
            cout << extra_votes << " ";
        } else {
            cout << -1 << " ";
        }
    }
    
    return 0;
}