#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
char s[MAXN], c[MAXN];

int solve(int n) {
    int ans = 0;
    
    // Try all three possible starting moves
    for (int first_move = 0; first_move < 3; first_move++) {
        int curr_ans = 0;
        char prev = ' ';
        
        // For each position, choose the optimal move that doesn't lose to the previous one
        for (int i = 1; i <= n; i++) {
            // Choose a move that doesn't lose to opponent
            if (s[i] == 'R') c[i] = 'P'; // Rock beats Paper
            if (s[i] == 'P') c[i] = 'S'; // Paper beats Scissors
            if (s[i] == 'S') c[i] = 'R'; // Scissors beats Rock
            
            // If we can't use our preferred move because it would be the same as previous
            if (i > 1 && c[i] == prev) {
                // We have to use the original move from the input string
                c[i] = s[i];
            } else {
                curr_ans++;
            }
            
            prev = c[i];
        }
        
        ans = max(ans, curr_ans);
        
        // Change the first move for next iteration
        if (first_move == 0) c[1] = 'R';
        else if (first_move == 1) c[1] = 'P';
        else c[1] = 'S';
    }
    
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1); // Read the opponent's moves
    
    printf("%d\n", solve(n));
    return 0;
}