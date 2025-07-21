#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    char past = 'N'; // Initialize to a dummy value
    int ans = 0;
    
    for (char c : S) {
        if (past == 'N') {
            // First move always counts as a win (since there's no previous move)
            ans++;
            past = c;
        } else {
            // Check if current move beats the opponent's last move
            if ((c == 'P' && past == 'R') ||
                (c == 'R' && past == 'S') ||
                (c == 'S' && past == 'P')) {
                ans++;
                past = c; // Update past to current move
            } else {
                // If not a win, keep the opponent's last move
                // (This was the main flaw in original code)
                past = c;
            }
        }
    }
    
    cout << ans;
    return 0;
}