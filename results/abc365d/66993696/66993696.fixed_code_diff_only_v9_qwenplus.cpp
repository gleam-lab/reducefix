#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200011;
char s[MAXN];
char c[MAXN];

int solve(int n, char first_char) {
    // Create mapping: beat the original character
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R'; // S -> R
    }
    
    // Set the first character as specified
    c[1] = first_char;
    
    int distinct_count = 1; // Start with first character
    
    // Process from second character onwards
    for (int i = 2; i <= n; i++) {
        // If current would be same as previous, we can choose original
        if (c[i] == c[i-1]) {
            c[i] = s[i]; // Choose original to break the sequence
        }
        if (i == 1 || c[i] != c[i-1]) {
            distinct_count++;
        }
    }
    
    return distinct_count;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Try all possible first characters and find maximum distinct adjacent count
    int ans = 0;
    
    // The first character can be any of the three types
    ans = max(ans, solve(n, 'P'));
    ans = max(ans, solve(n, 'R'));
    ans = max(ans, solve(n, 'S'));
    
    printf("%d\n", ans);
    return 0;
}