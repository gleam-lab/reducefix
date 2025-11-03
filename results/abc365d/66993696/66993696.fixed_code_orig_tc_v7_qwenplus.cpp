#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Define the winning move for each character
    auto win = [](char ch) {
        if (ch == 'P') return 'S';
        if (ch == 'R') return 'P';
        if (ch == 'S') return 'R';
        return ch;
    };
    
    // Try all three possible starting choices for the first position
    int ans = 0;
    
    for (char start : {'P', 'R', 'S'}) {
        c[1] = (s[1] == start) ? s[1] : win(s[1]);
        int sum = (c[1] == s[1]) ? 0 : 1;
        
        for (int i = 2; i <= n; i++) {
            c[i] = win(s[i]);
            // If there's a conflict with previous choice, we must choose opponent's move
            if (c[i] == c[i-1]) {
                c[i] = s[i];  // Choose the losing move (same as opponent)
                sum++;
            }
        }
        
        ans = max(ans, n - sum);
    }
    
    printf("%d", ans);
    return 0;
}