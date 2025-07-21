#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    if (N == 0) {
        cout << 0;
        return 0;
    }
    
    char past = S[0];  // Initialize with first move
    int ans = 1;       // Count the first move as a strategy
    
    for (int i = 1; i < N; i++) {
        char current = S[i];
        // Only count if current move beats the opponent's previous move
        if ((past == 'R' && current == 'P') ||
            (past == 'P' && current == 'S') ||
            (past == 'S' && current == 'R')) {
            ans++;
            past = current;  // Update past to this winning move
        }
        // Otherwise, keep the same strategy (don't increment count)
    }
    
    cout << ans;
    return 0;
}