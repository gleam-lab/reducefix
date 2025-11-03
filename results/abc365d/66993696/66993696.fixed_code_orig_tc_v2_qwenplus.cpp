#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Define transformation: each move beats the original
    auto transform = [](char ch) {
        if (ch == 'P') return 'S';
        if (ch == 'R') return 'P';
        return 'R'; // 'S' -> 'R'
    };
    
    // Try all possible starting positions for greedy fix
    int max_score = 0;
    
    for (int start = 0; start < 3; start++) {
        // Build transformed sequence with offset
        for (int i = 1; i <= n; i++) {
            c[i] = transform(s[i]);
        }
        
        // Apply cyclic shift based on start
        // This simulates different strategies of resolving conflicts
        for (int iter = 0; iter < start; iter++) {
            for (int i = 1; i <= n; i++) {
                if (c[i] == 'P') c[i] = 'S';
                else if (c[i] == 'R') c[i] = 'P';
                else c[i] = 'R';
            }
        }
        
        int score = n;
        // Fix adjacent duplicates greedily from left to right
        for (int i = 2; i <= n; i++) {
            if (c[i] == c[i-1]) {
                c[i] = s[i];  // Revert to original move
                score--;
            }
        }
        
        max_score = max(max_score, score);
    }
    
    // Also try fixing from right to left for better optimization
    for (int start = 0; start < 3; start++) {
        // Build transformed sequence with offset
        for (int i = 1; i <= n; i++) {
            c[i] = transform(s[i]);
        }
        
        // Apply cyclic shift based on start
        for (int iter = 0; iter < start; iter++) {
            for (int i = 1; i <= n; i++) {
                if (c[i] == 'P') c[i] = 'S';
                else if (c[i] == 'R') c[i] = 'P';
                else c[i] = 'R';
            }
        }
        
        int score = n;
        // Fix adjacent duplicates greedily from right to left
        for (int i = n-1; i >= 1; i--) {
            if (c[i] == c[i+1]) {
                c[i] = s[i];
                score--;
            }
        }
        
        max_score = max(max_score, score);
    }
    
    printf("%d\n", max_score);
    return 0;
}