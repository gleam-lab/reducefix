#include<bits/stdc++.h>
using namespace std;
char s[200011];
char visit[200011];  // To keep track of visited positions

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    
    // Initial pass to determine the necessary transformation
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            if (i % 2 == 0) visit[i] = 'S';  // Even index 'R' becomes 'S'
            else visit[i] = 'P';            // Odd index 'R' becomes 'P'
        } else {
            visit[i] = 'R';  // Non-'R' characters remain 'R'
        }
    }
    
    // Second pass to count the maximum sequence of 'R'S
    int maxSequence = 0, currentSequence = 0;
    for (int i = 0; i < n; ++i) {
        if (visit[i] == 'R') {
            currentSequence++;
            maxSequence = max(maxSequence, currentSequence);
        } else {
            currentSequence = 0;
        }
    }
    
    printf("%d", maxSequence);
    return 0;
}