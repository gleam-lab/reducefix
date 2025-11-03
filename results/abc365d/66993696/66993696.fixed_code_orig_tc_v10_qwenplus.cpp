#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Function to compute the score for a given starting choice
    auto getScore = [&](char start) {
        vector<char> res(n + 1);
        res[1] = start;
        int score = 0;
        
        for (int i = 1; i <= n; i++) {
            char beat = (s[i] == 'P') ? 'S' : (s[i] == 'R') ? 'P' : 'R';
            if (i == 1) {
                res[i] = beat;
            } else {
                if (res[i-1] == beat) {
                    res[i] = s[i]; // Choose same as opponent to avoid duplicate
                } else {
                    res[i] = beat;
                }
            }
            if (res[i] != s[i]) score++;
        }
        return score;
    };
    
    // Try all three possible choices for first move and take maximum
    int ans = 0;
    ans = max(ans, getScore('P'));
    ans = max(ans, getScore('R'));
    ans = max(ans, getScore('S'));
    
    printf("%d", ans);
    return 0;
}