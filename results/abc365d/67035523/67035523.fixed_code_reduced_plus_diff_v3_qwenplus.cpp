#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // shouldn't happen
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // dp[i][last] = minimum switches needed up to position i, ending with move last
    // We only need previous state, so use two arrays
    const long long INF = 1e18;
    vector<long long> prev(3, INF); // R=0, P=1, S=2
    
    // Initialize first character
    for (int j = 0; j < 3; j++) {
        char c = "RPS"[j];
        if (c == s[0]) 
            prev[j] = 0;
        else 
            prev[j] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        vector<long long> curr(3, INF);
        for (int last = 0; last < 3; last++) { // previous move
            if (prev[last] == INF) continue;
            char last_char = "RPS"[last];
            
            // Option 1: same as previous (no switch)
            if (s[i] == last_char) {
                curr[last] = min(curr[last], prev[last]);
            } else {
                curr[last] = min(curr[last], prev[last] + 1);
            }
            
            // Option 2: switch to a different move
            for (int cur = 0; cur < 3; cur++) {
                if (cur == last) continue;
                char cur_char = "RPS"[cur];
                if (s[i] == cur_char) {
                    curr[cur] = min(curr[cur], prev[last] + 1);
                } else {
                    curr[cur] = min(curr[cur], prev[last] + 2);
                }
            }
        }
        prev = curr;
    }
    
    long long ans = *min_element(prev.begin(), prev.end());
    cout << ans << endl;
    
    return 0;
}