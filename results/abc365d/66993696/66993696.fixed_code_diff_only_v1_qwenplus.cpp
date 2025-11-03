#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

char getWinningChar(char opponent) {
    if (opponent == 'P') return 'S';
    if (opponent == 'R') return 'P';
    if (opponent == 'S') return 'R';
    return ' ';
}

int solve(int n) {
    // Try all possible starting choices for first character
    int maxScore = 0;
    
    // We'll try three different strategies: keep original transformation or change first char to each option
    for (int startChoice = 0; startChoice < 3; startChoice++) {
        char choices[] = {'P', 'R', 'S'};
        c[1] = (startChoice == 0) ? getWinningChar(s[1]) : choices[startChoice-1];
        
        int score = 1; // First position always counts
        
        for (int i = 2; i <= n; i++) {
            c[i] = getWinningChar(s[i]);
            
            // If current choice is same as previous, we need to modify
            if (c[i] == c[i-1]) {
                // Try to use the original character instead
                char originalWin = getWinningChar(s[i]);
                char alternative = s[i]; // This will lose, but might break the streak
                
                // Check if using s[i] would still be valid (not equal to previous)
                if (alternative != c[i-1]) {
                    c[i] = alternative;
                }
                // Otherwise we have to keep the winning move even though it creates duplicate
                // This means we don't increment score
                else {
                    continue;
                }
            }
            score++;
        }
        
        maxScore = max(maxScore, score);
    }
    
    return maxScore;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Special case for n = 1
    if (n == 1) {
        printf("1");
        return 0;
    }
    
    int ans = 0;
    
    // Strategy 1: Always play to win when possible without consecutive duplicates
    for (int i = 1; i <= n; i++) {
        c[i] = getWinningChar(s[i]);
    }
    
    int sum = 1; // First position always contributes
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            // Can we use a non-winning move that doesn't create duplicate?
            if (s[i] != c[i-1]) {
                c[i] = s[i]; // Use original character (will lose, but avoids duplicate)
            } else {
                // Forced to have duplicate, so this position doesn't count
                continue;
            }
        }
        sum++;
    }
    ans = max(ans, sum);
    
    // Strategy 2: Try changing first move
    for (int firstChoice = 0; firstChoice < 3; firstChoice++) {
        char choices[] = {'P', 'R', 'S'};
        if (choices[firstChoice] == getWinningChar(s[1])) continue; // Skip if it's already the winning choice
        
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                c[i] = choices[firstChoice];
            } else {
                c[i] = getWinningChar(s[i]);
            }
        }
        
        int sum = 1; // First position counts since we're trying this strategy
        for (int i = 2; i <= n; i++) {
            if (c[i] == c[i-1]) {
                if (s[i] != c[i-1]) {
                    c[i] = s[i];
                } else {
                    continue;
                }
            }
            sum++;
        }
        ans = max(ans, sum);
    }
    
    printf("%d", ans);
    return 0;
}