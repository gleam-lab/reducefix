#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Function to compute score for a given starting choice
    auto getScore = [&](char start) {
        c[1] = start;
        int score = 1;
        
        for (int i = 2; i <= n; i++) {
            // Determine what we would normally beat
            char beats;
            if (s[i-1] == 'R') beats = 'P';
            else if (s[i-1] == 'P') beats = 'S';
            else beats = 'R';
            
            // If previous choice is already beating opponent, keep it
            if (c[i-1] == beats) {
                c[i] = c[i-1];
            } else {
                // Otherwise, choose the move that beats current opponent
                if (s[i] == 'R') c[i] = 'P';
                else if (s[i] == 'P') c[i] = 'S';
                else c[i] = 'R';
            }
            
            // Count if current move beats opponent
            if ((c[i] == 'R' && s[i] == 'S') ||
                (c[i] == 'P' && s[i] == 'R') ||
                (c[i] == 'S' && s[i] == 'P')) {
                score++;
            }
        }
        return score;
    };
    
    int ans = 0;
    // Try all three possible starting moves
    ans = max(ans, getScore('R'));
    ans = max(ans, getScore('P'));
    ans = max(ans, getScore('S'));
    
    printf("%d", ans);
    return 0;
}