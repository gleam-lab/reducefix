#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char beats(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return 'X'; // shouldn't happen
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // dp[i][c] = minimum moves to make prefix [0:i] end with character c
    // We only need previous state, so use two arrays
    vector<int> prev(3, 1e9);
    
    // Map: R->0, P->1, S->2
    auto getIdx = [](char c) {
        if (c == 'R') return 0;
        if (c == 'P') return 1;
        return 2;
    };
    
    auto getChar = [](int idx) {
        if (idx == 0) return 'R';
        if (idx == 1) return 'P';
        return 'S';
    };
    
    // Initialize for first character
    for (int i = 0; i < 3; i++) {
        char c = getChar(i);
        if (c == s[0]) 
            prev[i] = 0;
        else 
            prev[i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        vector<int> curr(3, 1e9);
        char target = s[i];
        
        for (int last = 0; last < 3; last++) {
            if (prev[last] == 1e9) continue;
            char lastChar = getChar(last);
            
            // Try keeping same as previous
            char newLastChar = lastChar;
            int cost = (newLastChar == target) ? 0 : 1;
            int idx = getIdx(newLastChar);
            curr[idx] = min(curr[idx], prev[last] + cost);
            
            // Try switching to what beats previous
            char beatChar = beats(lastChar);
            cost = (beatChar == target) ? 0 : 1;
            idx = getIdx(beatChar);
            curr[idx] = min(curr[idx], prev[last] + 1 + cost); // +1 for switch
        }
        
        prev = curr;
    }
    
    int result = *min_element(prev.begin(), prev.end());
    cout << result << endl;
    
    return 0;
}