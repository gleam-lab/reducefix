#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Define the winning move
    auto win = [](char ch) {
        if (ch == 'P') return 'S';
        if (ch == 'R') return 'P';
        return 'R';
    };
    
    // Try all three possible starting moves for the first character
    int ans = 0;
    for (char first : {'P', 'R', 'S'}) {
        c[1] = (s[1] == first) ? s[1] : win(s[1]);
        int sum = (s[1] == first) ? 0 : 1;
        
        for (int i = 2; i <= n; i++) {
            c[i] = win(s[i]);
            // If current move is same as previous, we lose this round
            if (c[i] == c[i-1]) {
                c[i] = s[i]; // Use opponent's move (we lose)
            } else {
                sum++;
            }
        }
        ans = max(ans, sum);
    }
    
    printf("%d\n", ans);
    return 0;
}